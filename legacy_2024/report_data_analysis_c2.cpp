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
unordered_map<int, vector<int>> fixedReports;

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
            vector<int> changedReport = parsedReports.at(i);
            bool damperResult = false;
            for (int k = 0; k < changedReport.size(); k++){
                auto changedCopy = changedReport;
                changedCopy.erase(changedCopy.begin() + k);
                damperResult = validityChecker(changedCopy);
                if (damperResult){
                    fixedReports.insert(fixedReports.begin(), pair<int, vector<int>>(i, changedCopy));
                    for (const auto& x : fixedReports) {
                        cout << "Fixed Report - " << x.first << " : [";
                        for (int v : x.second) {
                            cout << v << ' ';
                        }
                        cout << "]" << endl;
                    }
                    break;
                }
            }
            if (!damperResult){
                discardedReports.insert(discardedReports.begin(), pair<int, vector<int>> (i, parsedReports.at(i)));
            }
        }
    }

    cout << "Number of valid reports: " << validReports.size() << endl;
    cout << "Number of fixed reports: " << fixedReports.size() << endl;
    cout << "Totla number of valid reports : " << validReports.size() + fixedReports.size() << endl;
    cout << "Number of Discarded reports: " << discardedReports.size() << endl;

    return 0;
}


bool validityChecker(vector<int> report){

    int increasing_decreasing_trend = report.at(0) - report.at(1);
    int nonConformaceCount = 0;
    int nonConformanceIndex = -1;

    if (increasing_decreasing_trend >= 0){
        for(int i = 0; i < report.size() - 1; i++ ){
            int diff = report.at(i+1) - report.at(i);
            if (diff > -4 && diff < 0){
                continue;
            }
            else{
                nonConformaceCount++;
                nonConformanceIndex = i+1;
            }
        }
    }

    else {
        for(int i = 0; i < report.size() - 1; i++ ){
            int diff = report.at(i+1) - report.at(i);
            if (diff > 0 && diff < 4){
                continue;
            }
            else{
                nonConformaceCount++;
                nonConformanceIndex = i+1;
            }
        }
    }

    if (nonConformaceCount > 0 ) {
        return false;
    }
    else {
        return true;
    }
}




