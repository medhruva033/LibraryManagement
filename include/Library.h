#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <string>
#include <vector>

class Library {
private:
    std::vector<Book> books;
    std::string filename;

    static const int LOAN_DAYS = 14;
    static constexpr double FINE_PER_DAY = 2.0;

    int nextId() const;
    Book* findById(int id);

public:
    explicit Library(const std::string& filename);

    void addBook(const std::string& title, const std::string& author);
    bool removeBook(int id);
    void searchBooks(const std::string& keyword) const;
    void listBooks() const;
    bool issueBook(int id, const std::string& member);
    bool returnBook(int id);

    void load();
    void save() const;
};

#endif