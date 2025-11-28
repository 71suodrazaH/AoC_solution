#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string fileName = "xmas_word_data_file.txt";
string eachline;

vector<vector<char>> puzzleData;
string targetString = "XMAS";
string crossMas = "MAS";
bool printFuse = true;
int printCount = 0;

long counts = 0;

uint16_t forwardnBackwardHorizontalCount(void);
uint16_t forwardnBackwardVerticalCount(void);
uint16_t forwardnBackwardRightDiagnolCount(void);
uint16_t forwardnBackwardLeftDiagnolCount(void);
uint16_t X_mas_match_counts(void);

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
    
    // forwardnBackwardHorizontalCount();
    // forwardnBackwardVerticalCount();
    // forwardnBackwardRightDiagnolCount();
    // forwardnBackwardLeftDiagnolCount();

    // cout << "Total XMAS counts: " << counts << endl;

    uint16_t xmas_counts = X_mas_match_counts();
     cout << "Total X-MAS counts: " << xmas_counts << endl;

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
    uint16_t matches = 0;

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
                matches++;
                // cout << "Forward String: " << forwardString << endl;
                // cout << "Reverse String: " << reverseString << endl;
                // cout << "Count: " << counts << endl;
            }
            forwardString.clear();
            reverseString.clear();
        }
    }
    return matches;
}

uint16_t forwardnBackwardLeftDiagnolCount(void){
    string forwardString;
    string reverseString;
    uint16_t matches = 0;

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
                matches++;
                // cout << "Forward String: " << forwardString << endl;
                // cout << "Reverse String: " << reverseString << endl;
                // cout << "Count: " << counts << endl;
            }
            forwardString.clear();
            reverseString.clear();
        }
    }
    return matches;
}

uint16_t X_mas_match_counts(void){
    string x1_string;
    string x2_string;
    string reverse_x1_string;
    string reverse_x2_string;

    uint16_t matches = 0;

    for(int i = 1; i < puzzleData.size() - 1; i++){
        for (int j = 1; j <= puzzleData[i].size() - 1; j++){
            if (puzzleData[i][j] == 'A'){
                x1_string = string(1, puzzleData[i-1][j-1]) + puzzleData[i][j] + puzzleData[i+1][j+1];
                x2_string = string(1, puzzleData[i-1][j+1]) + puzzleData[i][j] + puzzleData[i+1][j-1];
                reverse_x1_string = x1_string;
                reverse_x2_string = x2_string;
                reverse(reverse_x1_string.begin(), reverse_x1_string.end());
                reverse(reverse_x2_string.begin(), reverse_x2_string.end());
                if ((x1_string  == crossMas || reverse_x1_string == crossMas) && (x2_string == crossMas || reverse_x2_string == crossMas)){
                    matches++;
                    cout << "X1_string : " << x1_string << ", X2_string: " << x2_string << endl;
                }
            }
        }
    }

    return matches;

}