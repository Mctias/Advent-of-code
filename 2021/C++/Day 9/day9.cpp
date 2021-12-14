#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>


using namespace std;

vector<int> extractInts1(string s){
    vector<int> result;
    result.push_back(INT_MAX);

    for(auto c : s){
        int x = c - '0';
        result.push_back(x);
    }
    result.push_back(INT_MAX);

    return result;
}

vector<int> extractInts2(string s){
    vector<int> result;
    //result.push_back(INT_MAX);

    for(auto c : s){
        int x = c - '0';
        result.push_back(x);
    }
    //result.push_back(INT_MAX);

    return result;
}

// Checks if current is basin and marks it as basin (-1)
// Then checks it neighbours using recursion
void checkBasin(vector<vector<int>> &data, int row, int col, int &size){

    size++;

    data[row][col] = -1;
    

    /*
        |
        x
    */

    if(row != 0 && data[row-1][col] != 9 && data[row-1][col] != -1){
        checkBasin(data, row-1, col, size);
    }
  
    /*
        x--
    */

    if(col != data[row].size() - 1 && data[row][col+1] != 9 && data[row][col+1] != -1){
        checkBasin(data, row, col+1, size);
    }

    /*
        x
        |
    */

    if(row != data.size() - 1 && data[row+1][col] != 9 && data[row+1][col] != -1){
        checkBasin(data, row+1, col, size);
    }

    /*
        --x
    */

    if(col != 0 && data[row][col-1] != 9 && data[row][col-1] != -1){
        checkBasin(data, row, col-1, size);
    }
}

void print(vector<vector<int>> in){
    for(auto i : in){
        for(auto j : i){
            std::cout << j << " ";
        }
        std::cout << endl;
    }
}

void part1(vector<vector<int>> data){
    int sum = 0;

    for(int i = 1; i < data.size()-1; i++){
        for(int j = 1; j < data[i].size()-1; j++){
            int val = data[i][j];
            if(val < data[i][j-1] && val < data[i][j+1] && val < data[i-1][j] && val < data[i+1][j])
                sum += val + 1;
        }
    }

    cout << "Result of part 1: " << sum << endl;
}

void part2(vector<vector<int>> data){
    int size = 0;
    vector<int> results;

    for(int i  = 0; i < data.size(); i++){
        for(int j = 0; j < data[i].size(); j++){
            if(data[i][j] != 9 && data[i][j] != -1){
                checkBasin(data, i, j, size);
                results.push_back(size);
            }
            
            size = 0;
        }
    }

    sort(results.begin(), results.end());

    int x = results[results.size() - 1];
    int y = results[results.size() - 2];
    int z = results[results.size() - 3];

    cout << "Result of part 2: " << x*y*z << endl;
}

int main(){
    vector<vector<int>> data1;
    vector<vector<int>> data2;
    vector<int> padding;

     // Data prep
    string fileName = "input.in";
    ifstream inputFile(fileName);
    
    string input;

    
    for(int i = 0 ; i < 102; i++){
        padding.push_back(INT_MAX);
    }
    data1.push_back(padding);

    while(getline(inputFile, input)){
        data1.push_back(extractInts1(input));
        data2.push_back(extractInts2(input));
    }

    data1.push_back(padding);

    part1(data1);
    part2(data2);
}