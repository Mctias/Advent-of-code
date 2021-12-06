#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int part1(string data){
    int sum = 0;

    for(int i = 0; i < data.length(); i++){
        string number = "";

        if(isdigit(data[i])){
            number += data[i];
            for(int j = i + 1; j < data.length(); j++){
                if(isdigit(data[j])){
                    number += data[j];
                }
                else{
                    break;
                }
            }

            if(data[i-1] == '-'){
                sum -= stoi(number);
            }
            else{
                sum += stoi(number);
            }

            i += number.length() - 1;
        }

        number = "";
    }

    return sum;

}

int main(){

    // Data prep

    string filename = "input.in";
    fstream inputFile(filename);

    string in;
    string data;

    while(inputFile >> in){
        data = in;
    }   

    int result_1 = part1(data); 
    cout << result_1;
}