#include <iostream>
#include <fstream>
#include<vector>
#include<cmath>

using std::cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: string;
using std::ifstream;


int main(){

    int i;
    string filename = "input.in";

    ifstream input_file(filename);

   vector<int> input;

    while(input_file >> i){
        input.push_back(i);
    }

    // Part 1
    input[1] = 12;
    input[2] = 2;


    int insertPos;
    int a, b;

    for(int i = 0; i < input.size(); i+=4){
        
        a = input[i + 1];
        b = input[i + 2];
        insertPos = input[i + 3];

        if(input[i] == 1){
            input[insertPos] = input[a] + input[b];
        }
        else if(input[i] == 2){
            input[insertPos] = input[a] * input[b];
        }
        else if(input[i] == 99) {
            break;
        }
    }

    cout << "Part 1: " << input[0];

    // Part 2
}