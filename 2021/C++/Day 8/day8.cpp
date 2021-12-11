#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

vector<string> wordSplit(string s){
    vector<string> result;
    string tmp = "";

    for(auto c : s){
        if(c == ' '){
            result.push_back(tmp);
            tmp = "";
        }
        else{
            tmp += c;
        }
    }

    return result;
}

void print(vector<vector<string>> in){
    for(auto i : in){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}


void part1(vector<vector<string>> data){
    int sum = 0;
    for(auto i : data){
        for(auto j : i){
            if(j.length() == 2 || j.length() == 3 
                || j.length() == 4 || j.length() == 7){
                    sum ++;
                }
        }
    }

    cout << "Result of part 1: " << sum << endl;
}

int main(){
    vector<vector<string>> inputData;
    vector<vector<string>> outputData;

     // Data prep 
    string fileName1 = "input.in";
    string fileName2 = "output.in";

    ifstream inputFile1(fileName1);
    ifstream inputFile2(fileName2);
    
    string input;
    while(getline(inputFile1, input)){
        inputData.push_back(wordSplit(input));
    }
    while(getline(inputFile2, input)){
        outputData.push_back(wordSplit(input));
    }

    part1(outputData);
}
/*
  0:      1:      2:      3:      4:
 aaaa    ....    aaaa    aaaa    ....
b    c  .    c  .    c  .    c  b    c
b    c  .    c  .    c  .    c  b    c
 ....    ....    dddd    dddd    dddd
e    f  .    f  e    .  .    f  .    f
e    f  .    f  e    .  .    f  .    f
 gggg    ....    gggg    gggg    ....

  5:      6:      7:      8:      9:
 aaaa    aaaa    aaaa    aaaa    aaaa
b    .  b    .  .    c  b    c  b    c
b    .  b    .  .    c  b    c  b    c
 dddd    dddd    ....    dddd    dddd
.    f  e    f  .    f  e    f  .    f
.    f  e    f  .    f  e    f  .    f
 gggg    gggg    ....    gggg    gggg
 */