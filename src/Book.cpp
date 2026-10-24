#include "Book.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

Book::Book() : id(0), title(""), author(""), issued(false), issuedTo(""), dueDate(0) {}

Book::Book(int id, const std::string& title, const std::string& author)
    : id(id), title(title), author(author), issued(false), issuedTo(""), dueDate(0) {}

int Book::getId() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
bool Book::isIssued() const { return issued; }
std::string Book::getIssuedTo() const { return issuedTo; }
long Book::getDueDate() const { return dueDate; }

void Book::issue(const std::string& member, long due) {
    issued = true;
    issuedTo = member;
    dueDate = due;
}

void Book::giveBack() {
    issued = false;
    issuedTo = "";
    dueDate = 0;
}

// Format: id|title|author|issued|issuedTo|dueDate
std::string Book::serialize() const {
    std::ostringstream out;
    out << id << "|" << title << "|" << author << "|"
        << (issued ? 1 : 0) << "|" << issuedTo << "|" << dueDate;
    return out.str();
}

Book Book::deserialize(const std::string& line) {
    std::vector<std::string> parts = Utils::split(line, '|');
    Book b;
    if (parts.size() < 6) return b;

    b.id = std::stoi(parts[0]);
    b.title = parts[1];
    b.author = parts[2];
    b.issued = (parts[3] == "1");
    b.issuedTo = parts[4];
    b.dueDate = std::stol(parts[5]);
    return b;
}

void Book::display() const {
    std::cout << std::left
              << std::setw(6)  << id
              << std::setw(30) << title
              << std::setw(22) << author
              << std::setw(12) << (issued ? "Issued" : "Available");
    if (issued) {
        std::cout << " -> " << issuedTo << " (due day " << dueDate << ")";
    }
    std::cout << "\n";
}