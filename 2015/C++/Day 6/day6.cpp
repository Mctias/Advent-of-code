#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
#include <string.h>
#include<vector>
#include<sstream>


using namespace std;
int grid[1000][1000] = {};

vector<string> splitString(const string str)
{
    vector<string> output;
    string::size_type start = 0; // Where to start
    string::size_type last = str.find_first_of(" "); // Finds the first space

    // npos means that the find_first_of wasn't able to find what it was looking for
    // in this case it means it couldn't find another space so we are at the end of the
    // words in the string.
    while (last != string::npos)
    {
        // If last is greater then start we have a word ready
        if (last > start)
        {
            output.push_back(str.substr(start, last - start)); // Puts the word into a vector look into how the method substr() works
        }

        start = ++last; // Reset start to the first character of the next word
        last = str.find_first_of(" ", last); // This means find the first space and we start searching at the first character of the next word
    }

    // This will pickup the last word in the file since it won't be added to the vector inside our loop
    output.push_back(str.substr(start));

    return output;
}

vector<int> extractInts(string s){
    stringstream ss;
    vector<int> result;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == ','){
            s[i] = ' ';
        }
    }

    ss << s;

    string tmpStr;
    int tmpInt;

    while(!ss.eof()){
        ss >> tmpStr;

        if(stringstream(tmpStr) >> tmpInt){
            result.push_back(tmpInt);
        }
        tmpStr = "";
    }
    return result;

}

int main(){
    // Data prep
    string filename = "input.in";
    fstream inputFile(filename);

    string in;
    vector<string> data;

    while(getline(inputFile, in)){
        data.push_back(in);
    }

    // Part 1 and Part 2

    // Change the if to this if you wanna do part 1
    /*if(command == "Toggle"){
        if(grid[j][k] == 1)
            grid[j][k] = 0;
        }

        else if(command == "on"){
            grid[j][k] = 1;
        }

        else if(command == "off"){
            grid[j][k] = 0;
    }
*/
   
   
   
    for(int i = 0; i < data.size(); i++){
        vector<string> splitWords = splitString(data[i]);

        string command;

        if(splitWords[0] != "turn")
            command = "Toggle";
        else
            command = splitWords[1];
    

        int lr = extractInts(data[i])[0];
        int lc = extractInts(data[i])[1];

        int ur = extractInts(data[i])[2];
        int uc = extractInts(data[i])[3];


        for(int j  = lr; j <= ur; j++){
            for(int k = lc; k <= uc; k++){

                if(command == "Toggle"){
                    grid[j][k] += 2;
                }

                else if(command == "on"){
                    grid[j][k] += 1;
                }

                else if(command == "off"){
                    grid[j][k] -= 1;

                    if(grid[j][k] <= 0)
                        grid[j][k] = 0;
                }

            }
        }
    }

    int brightness = 0;

    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            brightness += grid[i][j];
        } 
    }

    cout << brightness;
}