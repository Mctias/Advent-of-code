#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<math.h>
#include<unordered_map>

using namespace std;

pair<string,char> splitString(string s){

    string word = "";
    pair<string, char> result;

    char p1 = s[0];
    char p2 = s[1];
    string p = string() + p1 + p2;
    char c = s[2];

    result.first = p;
    result.second = c;

    return result;
    
}

int main(){
    string polymer = "SCVHKHVSHPVCNBKBPVHV";
    vector<pair<string, char>> instructions;

    // Data prep
    string fileName = "instructions.in";
    ifstream inputFile(fileName);
    
    string input;
 
    while(getline(inputFile, input)){
        instructions.push_back(splitString(input));
    }

    for(int x = 0; x < 10; x++){

        string tmp;

        for(int i = 0; i < polymer.length() - 1; i++){
            string p = string() + polymer[i] + polymer[i+1];
            char c;

            for(auto j : instructions){
                if(p == j.first){
                    c = j.second;
                }
            }
            if(i== 0)
                tmp += string() + polymer[i] + c + polymer[i+1];
            else
                tmp += string() + c + polymer[i+1];
        }

        polymer = tmp; 
        cout << x << endl;
    }

    unordered_map<char, long long> umap;

    for(auto c : polymer){
        if(umap.find(c) != umap.end()){
            umap[c]++;
        }
        else{
            umap[c] = 0;
        }
    }

    long long max = LLONG_MIN;
    long long min = LLONG_MAX;

    for(auto i : umap){
        if(i.second > max){
           max = i.second;
        }
        if(i.second < min){
            min = i.second;
        }
    }

    cout << "Result: " << max - min;
    



}