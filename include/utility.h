#pragma once

#include <string>

/**
 * @brief helper to turn a string into all lower case.
 *
 * @return string lower case
 */
std::string stringToLower(std::string str) {
    for (char& chr : str) {
        chr = tolower(chr);
    }
    return str;
}