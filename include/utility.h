#pragma once

#include <string>

std::string stringToLower(std::string str) {
    for (char& chr : str) {
        chr = tolower(chr);
    }
    return str;
}