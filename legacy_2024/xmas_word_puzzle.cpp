#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string fileName = "xmas_word_data_file.txt";
string eachline;

vector<vector<char>> puzzleData;
string targetString = "XMAS";
bool printFuse = true;
int printCount = 0;

long counts = 0;

uint16_t forwardnBackwardHorizontalCount(void);
uint16_t forwardnBackwardVerticalCount(void);
uint16_t forwardnBackwardRightDiagnolCount(void);
uint16_t forwardnBackwardLeftDiagnolCount(void);

int main(){

    ifstream inputPuzzleFile(fileName);
    if (inputPuzzleFile.is_open()){
        while(getline(inputPuzzleFile, eachline)){
            vector<char> row;
            for (auto z : eachline){
                row.push_back(z);
            }
            puzzleData.push_back(row);
        }
    }
    else {
        cout << "Could not open file, Exiting...";
        return -1;
    }

    inputPuzzleFile.close();
    
    forwardnBackwardHorizontalCount();
    forwardnBackwardVerticalCount();
    forwardnBackwardRightDiagnolCount();
    forwardnBackwardLeftDiagnolCount();
    // for (int i = 0; i < puzzleData.size(); i++)
    // {
    //     for (int j = 0; j < puzzleData[i].size(); j++)
    //     {
    //         cout << puzzleData[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "Total XMAS counts: " << counts << endl;

    return 0;
}

uint16_t forwardnBackwardHorizontalCount(void){
    string forwardString;
    string reverseString;

    for (int i = 0; i < puzzleData.size(); i++)
    {
        for (int j = 0; j < puzzleData[i].size() - targetString.size() + 1; j++)
        {
            for (int k = 0; k < targetString.size(); k++){
                forwardString.push_back(puzzleData[i][j+k]);
            }
            reverseString = forwardString;
            reverse(reverseString.begin(), reverseString.end());
            // if (printFuse && printCount < 20){
            //     cout << "\nForward String (until killing fuse): " << forwardString << endl;
            //     cout << "\nReverse String ((until killing fuse)): " << reverseString << endl;
            //     cout << "Count: " << counts << endl;
            //     printCount++;
            // }
            if (forwardString == targetString || reverseString == targetString){
                counts ++;
                // cout << "Forward String: " << forwardString << endl;
                // cout << "Reverse String: " << reverseString << endl;
                // cout << "Count: " << counts << endl;
            }
            forwardString.clear();
            reverseString.clear();
        }
    }
}


uint16_t forwardnBackwardVerticalCount(void){
    string forwardString;
    string reverseString;

    for (int i = 0; i < puzzleData.size() - targetString.size() + 1; i++)
    {
        for (int j = 0; j < puzzleData[i].size(); j++)
        {
            for (int k = 0; k < targetString.size(); k++){
                forwardString.push_back(puzzleData[i+k][j]);
            }
            reverseString = forwardString;
            reverse(reverseString.begin(), reverseString.end());
            // if (printFuse && printCount < 20){
            //     cout << "Forward String (until killing fuse): " << forwardString << endl;
            //     cout << "Reverse String ((until killing fuse)): " << reverseString << endl;
            //     cout << "Count: " << counts << endl;
            //     printCount++;
            // }
            if (forwardString == targetString || reverseString == targetString){
                counts ++;
                // cout << "Forward String: " << forwardString << endl;
                // cout << "Reverse String: " << reverseString << endl;
                // cout << "Count: " << counts << endl;
            }
            forwardString.clear();
            reverseString.clear();
        }
    }
}

uint16_t forwardnBackwardRightDiagnolCount(void){
    string forwardString;
    string reverseString;

    for (int i = 0; i < puzzleData.size() - targetString.size() + 1; i++)
    {
        for (int j = 0; j < puzzleData[i].size() - targetString.size() + 1; j++)
        {
            for (int k = 0; k < targetString.size(); k++){
                forwardString.push_back(puzzleData[i+k][j+k]);
            }
            reverseString = forwardString;
            reverse(reverseString.begin(), reverseString.end());
            // if (printFuse && printCount < 20){
            //     cout << "\nForward String (until killing fuse - diagonal): " << forwardString << endl;
            //     cout << "\nReverse String ((until killing fuse) - diagonal): " << reverseString << endl;
            //     cout << "Count: " << counts << endl;
            //     printCount++;
            // }
            if (forwardString == targetString || reverseString == targetString){
                counts ++;
                // cout << "Forward String: " << forwardString << endl;
                // cout << "Reverse String: " << reverseString << endl;
                // cout << "Count: " << counts << endl;
            }
            forwardString.clear();
            reverseString.clear();
        }
    }
}

uint16_t forwardnBackwardLeftDiagnolCount(void){
    string forwardString;
    string reverseString;

    for (int i = 0; i < puzzleData.size() - targetString.size() + 1; i++)
    {
        for (int j = puzzleData[i].size() - 1; j >= targetString.size() - 1; j--)
        {
            for (int k = 0; k < targetString.size(); k++){
                forwardString.push_back(puzzleData[i+k][j-k]);
            }
            reverseString = forwardString;
            reverse(reverseString.begin(), reverseString.end());
            if (printFuse && printCount < 20){
                cout << "\nForward String (until killing fuse - Left diagonal): " << forwardString << endl;
                cout << "\nReverse String ((until killing fuse) - Left diagonal): " << reverseString << endl;
                cout << "Count: " << counts << endl;
                printCount++;
            }
            if (forwardString == targetString || reverseString == targetString){
                counts ++;
                // cout << "Forward String: " << forwardString << endl;
                // cout << "Reverse String: " << reverseString << endl;
                // cout << "Count: " << counts << endl;
            }
            forwardString.clear();
            reverseString.clear();
        }
    }
}