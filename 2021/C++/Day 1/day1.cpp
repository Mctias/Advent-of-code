#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(){

    int in;
    string filename = "input.in";

    ifstream input_file(filename);

    vector<int> data;

    while(input_file >> in){
        data.push_back(in);
    }

    // Part 1

    int sum = 0;

    for(int x = 1; x < data.size(); x++){
        if(data[x] > data[x-1])
            sum++;
    }
    
    cout << "Part 1: " << sum <<endl;

    // Part 2

    sum = 0;

    int windowSum = INT_MAX;

    for(int x = 0; x < data.size() - 2; x++){

        int currSum = data[x] + data[x+1] + data[x+2];

        if(windowSum < currSum){
            sum++;
        }
        windowSum = currSum;
    }

    cout << "Part 2: "<< sum;
}