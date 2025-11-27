#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

string fileName = "corruption_c3.txt";
string eachline;
bool validNums = true;

long result = 0;

int main(){

    ifstream inputCorruptFile(fileName);
    if (inputCorruptFile.is_open()){
        while(getline(inputCorruptFile, eachline)){
            regex find_regex("(mul\\((\\d{1,3}),(\\d{1,3})\\))|(do\\(\\))|(don\\'t\\(\\))");
            auto begin_string = sregex_iterator(eachline.begin(), eachline.end(), find_regex);
            auto end_string = sregex_iterator();

            auto number_of_hits = distance(begin_string, end_string);

            for(sregex_iterator k = begin_string; k != end_string; ++k){

                smatch matched = *k;
                if (matched.str() == "don't()"){
                    validNums = false;
                }
                else if (matched.str() == "do()"){
                    validNums = true;
                }
                else {
                    if (validNums){
                        int num_1 = stoi(matched[2].str());
                        int num_2 = stoi(matched[3].str());
        
                        result += (num_1 * num_2);
                    }
                }
                
            }
        }
    }
    
    else {
        cout << "Could not open file, Exiting...";
        return -1;
    }

    inputCorruptFile.close();

    cout << "\nFinal result: " << result << endl;

    return 0;
}