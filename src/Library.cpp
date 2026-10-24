#include "Library.h"
#include "Utils.h"
#include <algorithm>
#include <fstream>
#include <iostream>

Library::Library(const std::string& filename) : filename(filename) {
    load();
}

int Library::nextId() const {
    int maxId = 0;
    for (const auto& b : books) {
        maxId = std::max(maxId, b.getId());
    }
    return maxId + 1;
}

Book* Library::findById(int id) {
    for (auto& b : books) {
        if (b.getId() == id) return &b;
    }
    return nullptr;
}

void Library::addBook(const std::string& title, const std::string& author) {
    int id = nextId();
    books.emplace_back(id, title, author);
    save();
    std::cout << "Book added with ID " << id << ".\n";
}

bool Library::removeBook(int id) {
    auto it = std::remove_if(books.begin(), books.end(),
                             [id](const Book& b) { return b.getId() == id; });
    if (it == books.end()) return false;
    books.erase(it, books.end());
    save();
    return true;
}

void Library::searchBooks(const std::string& keyword) const {
    std::string key = Utils::toLower(keyword);
    bool found = false;
    for (const auto& b : books) {
        if (Utils::toLower(b.getTitle()).find(key) != std::string::npos ||
            Utils::toLower(b.getAuthor()).find(key) != std::string::npos) {
            b.display();
            found = true;
        }
    }
    if (!found) std::cout << "No books matched \"" << keyword << "\".\n";
}

void Library::listBooks() const {
    if (books.empty()) {
        std::cout << "The library is empty.\n";
        return;
    }
    std::cout << "ID    Title                         Author                Status\n";
    std::cout << "-------------------------------------------------------------------\n";
    for (const auto& b : books) b.display();
}

bool Library::issueBook(int id, const std::string& member) {
    Book* b = findById(id);
    if (!b) {
        std::cout << "No book with ID " << id << ".\n";
        return false;
    }
    if (b->isIssued()) {
        std::cout << "That book is already issued to " << b->getIssuedTo() << ".\n";
        return false;
    }
    long due = Utils::today() + LOAN_DAYS;
    b->issue(member, due);
    save();
    std::cout << "Issued to " << member << ". Due in " << LOAN_DAYS << " days.\n";
    return true;
}

bool Library::returnBook(int id) {
    Book* b = findById(id);
    if (!b) {
        std::cout << "No book with ID " << id << ".\n";
        return false;
    }
    if (!b->isIssued()) {
        std::cout << "That book is not currently issued.\n";
        return false;
    }

    long overdue = Utils::today() - b->getDueDate();
    if (overdue > 0) {
        std::cout << "Book is " << overdue << " day(s) late. Fine: Rs. "
                  << overdue * FINE_PER_DAY << "\n";
    } else {
        std::cout << "Returned on time. No fine.\n";
    }
    b->giveBack();
    save();
    return true;
}

void Library::load() {
    std::ifstream in(filename);
    if (!in) return;

    books.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        books.push_back(Book::deserialize(line));
    }
}

void Library::save() const {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Warning: could not save to " << filename << "\n";
        return;
    }
    for (const auto& b : books) {
        out << b.serialize() << "\n";
    }
}