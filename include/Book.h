#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool issued;
    std::string issuedTo;
    long dueDate;   // days since epoch, 0 if not issued

public:
    Book();
    Book(int id, const std::string& title, const std::string& author);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool isIssued() const;
    std::string getIssuedTo() const;
    long getDueDate() const;

    void issue(const std::string& member, long due);
    void giveBack();

    std::string serialize() const;
    static Book deserialize(const std::string& line);

    void display() const;
};

#endif