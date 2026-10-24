CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
SRC = $(wildcard src/*.cpp)
TARGET = library

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)