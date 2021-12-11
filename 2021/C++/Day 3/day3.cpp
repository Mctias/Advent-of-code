#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;

vector<int> splitString(string s){

    string word = "";
    vector<int> result;

    for(auto c : s){
        int x = c - '0';
        result.push_back(x);
    }
    
    return result;
}

int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

void deleteRows(vector<vector<int>>& data, bool zero, int col){

    for(int i = 0; i < data.size(); i++){
        if(zero){
            if(data[i][col] == 1){
                data.erase(data.begin() + i);
                i -= 1;
            }
        }
        else{
            if(data[i][col] == 0){
                data.erase(data.begin() + i);
                i -= 1;
            }
        }
    }

}

int calcOxygen(vector<vector<int>> data){
    // Oxygen

    for(int i = 0; i < data[0].size(); i++){
         int zeroCount = 0; 
         int oneCount = 0;

        for(int j = 0; j < data.size(); j++){
          if(data[j][i] == 0){
                zeroCount++;
            }
            else{
                oneCount++;
            }
        }
        if(zeroCount > oneCount){
            deleteRows(data, true, i);
        }
        else if(zeroCount <= oneCount){
            deleteRows(data, false, i);
        }
        if(data.size() == 1)
            break;
    }

    string oxygen = "";

    for(auto i : data){
        for(auto j : i){
            if(j == 1)
                oxygen += "1";
            else
                oxygen += "0";
        }
    }

    return convert(stoll(oxygen));

}

int calcC02(vector<vector<int>> data){
    for(int i = 0; i < data[0].size(); i++){
         int zeroCount = 0; 
         int oneCount = 0;

        for(int j = 0; j < data.size(); j++){
          if(data[j][i] == 0){
                zeroCount++;
            }
            else{
                oneCount++;
            }
        }
        if(zeroCount <= oneCount){
            deleteRows(data, true, i);
        }
        else if(zeroCount > oneCount){
            deleteRows(data, false, i);
        }
        if(data.size() == 1)
            break;
    }
    
    string C02 = "";

    for(auto i : data){
        for(auto j : i){
            if(j == 1)
                C02 += "1";
            else
                C02 += "0";
        }
    }

    return convert(stoll(C02));
}

void part1(vector<vector<int>> data){
    string gamma;
    string epsilon;

    for(int i = 0; i < data[0].size(); i++){
         int zeroCount = 0; 
         int oneCount = 0;
       

        for(int j = 0; j < data.size(); j++){
            if(data[j][i] == 0){
                zeroCount++;
            }
            else{
                oneCount++;
            }
        }
        
        if(zeroCount > oneCount){
            gamma += "0";
            epsilon += "1";
        }
        else{
            gamma += "1";
            epsilon += "0";
        }
    }

    long long  gammaDec = convert(stoll(gamma));
    long long epsilonDec = convert(stoll(epsilon));

    cout << "Part 1: " <<  gammaDec * epsilonDec << endl;

}

void part2(vector<vector<int>> data){
    cout << "Part 2: " <<calcOxygen(data) * calcC02(data);
}

int main(){

    string in;
    string filename = "input.in";
    ifstream input_file(filename);

    vector<vector<int>> data;

    while(getline(input_file, in)){
        data.push_back(splitString(in));
    }

    part1(data);
    part2(data);
}