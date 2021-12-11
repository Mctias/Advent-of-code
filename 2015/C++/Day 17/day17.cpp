#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(){
    
    //vector<int> data = {20, 5, 15, 10 ,5};
    vector<int> data = {11, 30, 47, 31, 32, 36, 3, 1, 5, 3, 32, 36, 15, 11, 46, 26, 28, 1, 19 ,3};

    vector<int> copy = data;

    int count = 0;

    for(int i = 0; i < data.size(); i++){
        int sum = data[i];
        for(int j = i + 1; j < copy.size(); j++){
            sum += copy[j];
            if(sum > 150){
                copy.erase(copy.begin() + j);
                j = i;
                sum = data[i];
            }
            else if(sum == 150){
                copy.erase(copy.begin() + j);
                j = i;
                count++;
                sum = data[i];
            }
        }
        copy = data;

    }

    cout << count;

    




}