#pragma once

#include <string>
#include <utility>

// Parse a line like "123   456" into two ints.
std::pair<int, int> parseLineToTwoInts(const std::string& line);