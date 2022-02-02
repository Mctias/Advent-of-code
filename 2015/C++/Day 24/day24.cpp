#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;
            
int main(){
    vector<int> data;
    int in;

    string filename = "input.in";

    ifstream input_file(filename);

    while(input_file >> in){
        data.push_back(in);
    }

    int target = 384; 
    vector<long long> results;
    
    // I figured out it hade to be four presents so I just brute forced it...
    // Figured out the first part by looking at the data

    for(int i = 0; i < data.size(); i++){
        for(int j = i+1; j < data.size(); j++){
            for(int k = j+1; k < data.size(); k++){
                for(int l = k+1; l < data.size(); l++){
                    int sum = data[i] + data[j] + data[k] + data[l];
                    if(sum == target){
                        long long q = data[i] * data[j] * data[k] * data[l];
                        results.push_back(q);
                    }
                }
            }
        }
    }
    
    long long min = LLONG_MAX;

    for(auto x : results){
        if(x < min){
            min = x;
        }
    }
    
    cout << min << endl;
}