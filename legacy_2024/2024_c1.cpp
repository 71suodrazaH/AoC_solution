#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "helpers/line_parser.hpp"
#include <set>

using namespace std;

string eachLine;
long sum = 0;
long similarity_score = 0;


vector <int> leftList;
vector <int> rightList;
vector <int> distace;


int main(){
    ifstream readTxtFile("data_dump.txt");
    cout << "Tried to read file" << '\n';
    if (readTxtFile.is_open()){
        while (getline(readTxtFile, eachLine)){
            auto [left, right] = parseLineToTwoInts(eachLine);
            leftList.push_back(left);
            rightList.push_back(right);
        }
    }
    else{
        cout << "Could not open requested file" << '\n';
    }
    readTxtFile.close();

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    cout << "Length of the left list : " << leftList.size() << '\n';
    cout << "Length of the right list : " << rightList.size() << '\n';

    for (int j=0; j<leftList.size(); j++){
        int val = abs(leftList.at(j) - rightList.at(j));
        distace.push_back(val);
        sum += val;
    }

    cout << "Final value: " << sum << '\n';

    // similarity score

    set <int> uniqueLeftSet (leftList.begin(), leftList.end());
    unordered_map <int, int> occurenceMap;

    cout << "Number of unique elements in leftList: " << uniqueLeftSet.size() << '\n';

    for (auto it = uniqueLeftSet.begin(); it != uniqueLeftSet.end(); ++it){
        occurenceMap.insert(occurenceMap.begin(), pair<int, int>(*it, 0));
    }

    for (auto i : rightList){
        auto it = occurenceMap.find(i);
        if (it != occurenceMap.end()){
            int tmp = it->second;
            occurenceMap.at(it->first) = tmp + 1;
        }
    }

    for (auto x : occurenceMap){
        similarity_score += (x.first * x.second);
    }

    cout << "Similarity Score : " << similarity_score << endl;
    
    
}


