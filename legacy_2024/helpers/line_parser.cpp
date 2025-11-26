#include "line_parser.hpp"
#include <sstream>
#include <stdexcept>

using namespace std;

pair<int, int> parseLineToTwoInts(const string& line) {
    istringstream iss(line);
    int left = 0;
    int right = 0;

    if (!(iss >> left >> right)) {
        throw std::runtime_error("Failed to parse line: " + line);
    }

    return {left, right};
}

vector <int> parseLineMultiInts(const string& line){

    vector<int> result;
    istringstream inputLineStream(line);

    int num;
    while (inputLineStream >> num){
        result.push_back(num);
    }

    return result;
}