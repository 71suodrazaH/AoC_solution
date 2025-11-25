#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string eachLine;
int i = 0;
int sum = 0;

struct {
    int item_L;
    int item_R;
} values;

vector <int> leftList;
vector <int> rightList;
vector <int> distace;


void extractValues(string lineInput){

    lineInput.push_back(' ');
    string tmpArr;
    int i = 0;
    int catcher = 0;

    while (i < (lineInput.length() + 1)){
        if (lineInput[i] != ' '){
            tmpArr += lineInput[i];
        }
        else{
            if (tmpArr.length() > 2){
                
                switch (catcher)
                {
                case 0:
                    // cout << "Trying to convert value : " << tmpArr << '\n';
                    values.item_L = stoi(tmpArr);
                    catcher ++;
                    tmpArr.erase();
                    break;

                case 1:
                    values.item_R = stoi(tmpArr);
                    break;

                default:
                    cout << "unknown case occured" << '\n';
                    break;
                }
           }
        }
        i++;
    }

    // cout << "Extracted Values : " << values.item_L << " " << values.item_R << '\n';

}

int main(){
    ifstream readTxtFile("data_dump.txt");
    cout << "Tried to read file" << '\n';
    if (readTxtFile.is_open()){
        while (getline(readTxtFile, eachLine)){
            extractValues(eachLine);
            leftList.push_back(values.item_L);
            rightList.push_back(values.item_R);
        }
    }
    else{
        cout << "Could not open requested file" << '\n';
    }

    sort(leftList.begin(), leftList.end());
    sort(rightList.begin(), rightList.end());

    cout << "Length of the left list : " << leftList.size() << '\n';
    cout << "Length of the right list : " << rightList.size() << '\n';

    for (int j=0; j<leftList.size(); j++){
        int val = abs(leftList.at(j) - rightList.at(j));
        // cout << val << '\n';
        distace.push_back(val);
        sum += val;
    }

    cout << "Final value: " << sum << '\n';

    readTxtFile.close();
}


