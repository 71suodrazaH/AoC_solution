#pragma once

#include <string>
#include <utility>
#include <vector>

using namespace std;

// Parse a line like "123   456" into two ints.
pair<int, int> parseLineToTwoInts(const string& line);

vector <int> parseLineMultiInts(const string& line);

