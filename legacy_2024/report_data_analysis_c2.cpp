#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "helpers/line_parser.hpp"

using namespace std;

const string FileName = "reports_data_c2.txt";
string eachLine;
unordered_map<int, vector<int>> parsedReports;
unordered_map<int, vector<int>> validReports;
unordered_map<int, vector<int>> discardedReports;

int position = 1;

bool validityChecker(vector<int> report);


int main(){

    ifstream reportFile(FileName);
    if (reportFile.is_open()){
        while(getline(reportFile, eachLine)){
            vector<int> tmp = parseLineMultiInts(eachLine);
            parsedReports.insert(parsedReports.begin(), pair<int, vector<int>> (position, tmp));
            position++;
        }
        reportFile.close();
    }
    else{
        cout << "Failed to open reports file, Exiting ..." << endl;
        return -1;
    }

    cout << "Checking number of elements in hashMap: " << parsedReports.size() << endl;
    for (int i = 1; i < position; i++){
        bool result = validityChecker(parsedReports.at(i));
        if (result){
            validReports.insert(validReports.begin(), pair<int, vector<int>> (i, parsedReports.at(i)));
        }
        else{
            discardedReports.insert(discardedReports.begin(), pair<int, vector<int>> (i, parsedReports.at(i)));
        }
    }

    cout << "Number of valid reports: " << validReports.size() << endl;

    for (const auto& x : validReports) {
        cout << x.first << " : [";
        for (int v : x.second) {
            cout << v << ' ';
        }
        cout << "]" << endl;
    }

    cout << "Number of Discarded reports: " << discardedReports.size() << endl;

    for (const auto& x : discardedReports) {
        cout << x.first << " : [";
        for (int v : x.second) {
            cout << v << ' ';
        }
        cout << "]" << endl;
    }

    return 0;
}


bool validityChecker(vector<int> report){

    int increasing_decreasing_trend = report.at(0) - report.at(1);

    if (increasing_decreasing_trend > 0){
        for(int i = 0; i < report.size() - 1; i++ ){
            int diff = report.at(i+1) - report.at(i);
            if (diff > -4 && diff < 0){
                continue;
            }
            else{
                return false;
            }
        }
    }

    else if (increasing_decreasing_trend < 0)
    {
        for(int i = 0; i < report.size() - 1; i++ ){
            int diff = report.at(i+1) - report.at(i);
            if (diff > 0 && diff < 4){
                continue;
            }
            else{
                return false;
            }
        }
    }

    else {
        return false;
    }

    return true;
    
}




