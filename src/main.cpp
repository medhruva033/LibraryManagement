#include "Library.h"
#include "Utils.h"
#include <iostream>

void showMenu() {
    std::cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n"
              << "1. Add book\n"
              << "2. Remove book\n"
              << "3. Search books\n"
              << "4. List all books\n"
              << "5. Issue book\n"
              << "6. Return book\n"
              << "0. Exit\n";
}

int main() {
    Library library("data/books.txt");

    while (true) {
        showMenu();
        int choice = Utils::readInt("Enter choice: ");

        switch (choice) {
            case 1: {
                std::string title = Utils::readLine("Title: ");
                std::string author = Utils::readLine("Author: ");
                library.addBook(title, author);
                break;
            }
            case 2: {
                int id = Utils::readInt("Book ID to remove: ");
                if (library.removeBook(id)) std::cout << "Book removed.\n";
                else std::cout << "No book with that ID.\n";
                break;
            }
            case 3: {
                std::string keyword = Utils::readLine("Search (title or author): ");
                library.searchBooks(keyword);
                break;
            }
            case 4:
                library.listBooks();
                break;
            case 5: {
                int id = Utils::readInt("Book ID to issue: ");
                std::string member = Utils::readLine("Member name: ");
                library.issueBook(id, member);
                break;
            }
            case 6: {
                int id = Utils::readInt("Book ID to return: ");
                library.returnBook(id);
                break;
            }
            case 0:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}