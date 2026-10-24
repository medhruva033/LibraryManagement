#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace Utils {
    std::vector<std::string> split(const std::string& s, char delimiter);
    std::string toLower(std::string s);
    long today();
    int readInt(const std::string& prompt);
    std::string readLine(const std::string& prompt);
}

#endif