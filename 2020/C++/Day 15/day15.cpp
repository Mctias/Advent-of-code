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

int search(vector<int> seq, int key){
    for(int i = seq.size() - 2; i >= 0; i--){
        if(seq[i] == key)
            return i;
    }

    return -1;

}

int check(unordered_map<int, int> &umap, int prevNum, int turn){
    int newNum;

    if(umap.find(prevNum) != umap.end()){
        newNum = turn - umap[prevNum];
    }
    else{
        newNum = 0;
    }

    umap[prevNum] = turn;
    return newNum;
}

unordered_map<int,int> createHashMap(vector<int> input){

    unordered_map<int,int> umap;

    for(int i = 1; i < input.size(); i++){
        umap[input[i-1]] = i;
    }
    return umap;

}


int main(){ 

    int i;
    int count = 0;
    int limit = 30000000;
    string filename = "input.in";

    ifstream input_file(filename);

    vector<int> input;
    while(input_file >> i){
        input.push_back(i);
    }
    unordered_map<int, int> umap = createHashMap(input);

    // Part 1
    /*
    for(int i = 7; i < limit; i++){
        cout << i << endl;
        int lastIndex = search(input, input[i - 1]);
        if( lastIndex != -1){
            input.push_back((i - 1) - lastIndex);
        }
        else{
            input.push_back(0);
        }
    }  
*/
    // Part 2
    

    int turn = input.size();
    int prevNum = input[turn - 1]; 
    
    

    while(turn != limit){
        prevNum = check(umap, prevNum, turn++);
    }
    
    cout << prevNum;
}