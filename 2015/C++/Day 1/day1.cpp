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

    char in;
    string filename = "input.in";

    ifstream input_file(filename);

    vector<char> data;
    while(input_file >> in){
        data.push_back(in);
    }

    //Part 1

    int floor = 0;

    for(auto i : data){
        if(i == '(')
            floor++;
        else if(i == ')')
            floor--;
    }

    cout << floor << endl;

    // Part 2

    int floor2 = 0;

    for(int i = 0; i < data.size(); i++){
        if(data[i] == '(')
            floor2++;
        else if(data[i] == ')')
            floor2--;

        if(floor2 == -1){
            cout << i + 1;
            break;
        }

    }




}