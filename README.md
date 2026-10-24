# Library Management System (C++)

A console-based library system built with C++17 and OOP.

## Features
- Add, remove, search and list books
- Issue and return books with a 14-day loan period
- Automatic fine calculation for late returns
- Data saved to a text file between runs

## Build and run
    g++ -std=c++17 -Iinclude src/*.cpp -o library
    ./library

Run from the project root so data/books.txt resolves correctly.