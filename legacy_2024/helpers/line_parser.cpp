#include "line_parser.hpp"
#include <sstream>
#include <stdexcept>

std::pair<int, int> parseLineToTwoInts(const std::string& line) {
    std::istringstream iss(line);
    int left = 0;
    int right = 0;

    if (!(iss >> left >> right)) {
        throw std::runtime_error("Failed to parse line: " + line);
    }

    return {left, right};
}