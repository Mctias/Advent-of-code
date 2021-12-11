#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <regex>

using namespace std;

int part1(string s){
    
    // Find all of our special characters with some regex magic
    // Then reduce these to one char
    // Lastly return the length of the resulting string

    regex openingQuotes("^\"|\"$");
    regex hexadecimal("\\\\x[a-zA-Z0-9]{2}");
    regex doubleSlash("\\\\\\\\");
    regex slashQuotes("\\\\\"");

    s = regex_replace(s, openingQuotes, "");
    s = regex_replace(s, doubleSlash, "_");
    s = regex_replace(s, hexadecimal, "_");
    s = regex_replace(s, slashQuotes, "_");
    
    return s.length();

}

int part2(string s){

    // Same thing as part one but replace our specials with the corresponding number of new characters

    regex openingQuotes("^\"|\"$");
    regex hexadecimal("\\\\x[a-zA-Z0-9]{2}");
    regex doubleSlash("\\\\\\\\");
    regex slashQuotes("\\\\\"");

    
    s = regex_replace(s, openingQuotes, "___");
    s = regex_replace(s, doubleSlash, "____");
    s = regex_replace(s, hexadecimal, "_____");
    s = regex_replace(s, slashQuotes, "____");
    


    return s.length();

}

int main(){
    string in;
    string filename = "input.in";

    ifstream input_file(filename);

    vector<string> data;
    while(input_file >> in){
        data.push_back(in);
    }

    int charMem = 0;
    int charNum1 = 0;

    for(auto i : data){
        charNum1 += i.length();
        charMem += part1(i);
    }

    cout << "Result of part 1: " << charNum1 - charMem << endl;

    int charNum2 = 0;

    for(auto i : data){
        charNum2 += part2(i);
    }

    cout << "Result of part 2: " << charNum2 - charNum1;
}