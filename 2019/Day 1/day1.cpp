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
    int resultA = 0;
    for(auto i : input){
        resultA += floor(i/3) - 2;
    }

    cout << "A: "<<resultA << endl;

    // Part 2
    vector<int> sums;

    int res = 0; 
    int sum;

    for(auto i : input){
        sum = floor(i/3) - 2;

        res += sum;
        
        while((floor(sum/3) - 2) > 0){
            sum = floor(sum/3) - 2;
            res += sum;
        }

        sums.push_back(res);
        res = 0;
    }

    int resultB = 0;
    for(auto i : sums){
        resultB += i;
    }

    cout << "B: " <<resultB;


}