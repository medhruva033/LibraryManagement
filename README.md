# Library Management System in C++

A console-based **Library Management System** built with C++17 using Object-Oriented Programming (OOP). The application manages book records, tracks book loans, and calculates fines for overdue returns.

## Features

- **Book Management:** Add, remove, search, and list books.
- **Book Issuing:** Issue books to members with a 14-day loan period.
- **Book Returns:** Return issued books and update their availability.
- **Fine Calculation:** Calculate fines for overdue books.
- **Data Persistence:** Store library records in a text file between program runs.
- **Input Validation:** Handle invalid menu selections and book IDs.

## Tech Stack

- **Language:** C++17
- **Programming Concepts:** OOP, classes, encapsulation, functions
- **Data Structures:** STL containers
- **File Handling:** C++ file streams
- **Build Tools:** GCC / G++, CMake, Make

## Project Structure

```text
LibraryManagement/
├── include/
│   ├── Book.h
│   ├── Library.h
│   └── Utils.h
├── src/
│   ├── main.cpp
│   ├── Book.cpp
│   ├── Library.cpp
│   └── Utils.cpp
├── data/
│   └── books.txt
├── CMakeLists.txt
├── Makefile
└── README.md
```

## Build and Run

### Windows (G++)

Compile from the project root:

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/Book.cpp src/Library.cpp src/Utils.cpp src/main.cpp -o library.exe
```

Run the program:

```cmd
library.exe
```

### Linux / macOS (G++)

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/Book.cpp src/Library.cpp src/Utils.cpp src/main.cpp -o library
./library
```

**Important:** Run the program from the project root so the relative path `data/books.txt` resolves correctly.

## Learning Outcomes

This project demonstrates practical use of:

- Object-Oriented Programming in C++
- Modular code organization using header and source files
- File handling and persistent data
- Input validation and error handling
- Basic software project structure and build workflows

## Future Improvements

- Member registration and management
- Improved input validation
- Human-readable due dates
- Unit testing
- Database integration
- Enhanced reporting and overdue-book tracking

## Author

**Dhruva M. K.**

GitHub: [@medhruva033](https://github.com/medhruva033)
