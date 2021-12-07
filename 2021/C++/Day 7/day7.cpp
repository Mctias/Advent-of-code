#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int main(){
    vector<int> data;

    vector<int> results;

     // Data prep - Read the sequence from input1.in and the boards from input2.in
    string fileName = "input.in";

    ifstream inputFile(fileName);
    
    int input;
    while(inputFile >> input){
        data.push_back(input);
    }

    for(int i = 0; i < data.size(); i++){
        int comparePos = data[i];
        int sum = 0;

        for(int j = 0; j < data.size(); j++){
            if(data[j] <= data[i]){
                sum += data[i] - data[j];
            }
            else{
                sum += data[j] - data[i];
            }
        }
        results.push_back(sum);
    }

    cout << *min_element (results.begin(), results.end());
}