#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

vector<string> splitString(string s){
    vector<string> result;
    string word = "";

    for(auto c : s){
        if(c == ',')
            continue;
        if(c == ' '){
            result.push_back(word);
            word = "";
        }
        else{
            word += c;
        }
    }
    return result;
}

int main(){

    // Data prep
    string filename = "input.in";
    fstream inputFile(filename);

    string in;
    vector<vector<string>> instructions;

    while(getline(inputFile, in)){
        instructions.push_back(splitString(in));
    }

    long long a = 1;
    long long b = 0;

    for(int i = 0; i < instructions.size(); i++){
        
        if(instructions[i][0] == "inc"){
            if(instructions[i][1] == "a")
                a++;
            else
                b++;
        }
        else if(instructions[i][0] == "tpl"){
            if(instructions[i][1] == "a")
                a*=3;
            else
                b*=3;
        }
        else if(instructions[i][0] == "hlf"){
            if(instructions[i][1] == "a")
                a/=2;
            else
                b/=2;
        }

        else if(instructions[i][0] == "jmp"){
            int num = stoi(instructions[i][1]) - 1;

            i += num;
        }
        else if(instructions[i][0] == "jio"){
            int num = stoi(instructions[i][2]) - 1;

            if(instructions[i][1] == "a"){
                if(a == 1){
                    i += num;
                }
            }
            else{
                if(b == 1){
                    i += num;
                }
            }

        }
        else if(instructions[i][0] == "jie"){
            int num = stoi(instructions[i][2]) - 1;

            if(instructions[i][1] == "a"){
                if(a % 2 == 0){
                    i += num;
                }
            }
            else{
                if(b % 2 == 0){
                    i += num;
                }
            }

        }

        if(i < 0 || i >= instructions.size())
            break;
    }

    cout << b;



}