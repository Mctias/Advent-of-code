#include <iostream>
#include <fstream>
#include<vector>
#include<cmath>
#include<unordered_map>

using std::cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: string;
using std::ifstream;
using std::unordered_map;

int fly(int angle, int speed, vector<string> input){
    int counter = 0;
    int slope = 0;
    for(int i = speed; i < input.size(); i += speed){
        slope += angle;
        if(slope >= input[0].length()){
            slope = slope - input[i].length();
        }

        if(input[i][slope] == '#'){
            counter++;
        }
        else{
            continue;
        }
    }
    return counter;
}

int main(){ 
    string filename = "input.in";

    ifstream input_file(filename);

    vector<string> input;
    string i; 

    while(input_file >> i){
        input.push_back(i);
    }
    long long result = 1;

    result *= fly(1, 1, input);
    result *= fly(3, 1, input);
    result *= fly(5, 1, input);
    result *= fly(7, 1, input);
    result *= fly(1, 2, input);

    

   cout << result;
    
}

