#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

vector<string> splitString(string s){

    string word = "";
    vector<string> result;

    for(auto c : s){

        if(c == ' '){
            result.push_back(word);
            word = "";
        }
        else{
             word += c;
        }
    }
    
    return result;
}

int main(){

    string in;
    string filename = "input.in";
    ifstream input_file(filename);

    vector<vector<string>> data;

    while(getline(input_file, in)){
        data.push_back(splitString(in));
    }

    // Part 1

    int x = 0;
    int y = 0;

    for(int i = 0; i < data.size(); i++){
        if(data[i][0] == "forward")
            x += stoi(data[i][1]); 
        else if(data[i][0] == "down")
            y += stoi(data[i][1]); 
        else if(data[i][0] == "up")
            y -= stoi(data[i][1]); 
    }

    cout << "Part 1: " << x * y << endl;

    // Part 2

    x = 0;
    y = 0;
    int aim = 0;
    


    for(int i = 0; i < data.size(); i++){
        if(data[i][0] == "forward"){
            x += stoi(data[i][1]);
            if(aim > 0)
                y += aim * stoi(data[i][1]);
        } 
        else if(data[i][0] == "down")
            aim += stoi(data[i][1]); 
        else if(data[i][0] == "up")
            aim -= stoi(data[i][1]); 
    }
    cout << "Part 2: "<< x * y << endl;
}