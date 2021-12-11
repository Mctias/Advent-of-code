#include<iostream>
#include<vector>
#include<fstream>
#include<string>


using namespace std;

// Get the numbers for the boards
vector<int> extractInts(string s){
    vector<int> result;
    result.push_back(INT_MAX);

    for(auto c : s){
        int x = c - '0';
        result.push_back(x);
    }
    result.push_back(INT_MAX);

    return result;
}


int main(){
    vector<vector<int>> data;
    vector<int> padding;

     // Data prep
    string fileName = "input.in";
    ifstream inputFile(fileName);
    
    string input;

    for(int i = 0 ; i < 102; i++){
        padding.push_back(INT_MAX);
    }
    data.push_back(padding);

    while(getline(inputFile, input)){
        data.push_back(extractInts(input));
    }

    data.push_back(padding);

    int sum = 0;

    for(int i = 1; i < data.size()-1; i++){
        for(int j = 1; j < data[i].size()-1; j++){
            int val = data[i][j];
            if(val < data[i][j-1] && val < data[i][j+1] && val < data[i-1][j] && val < data[i+1][j])
                sum += val + 1;

        }
          
    }

    cout << sum;
}