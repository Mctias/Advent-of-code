//
//
// Never ever show this code to anyone
//
//




#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std:: vector;
using std:: string;
using std::ifstream;
using std::stoi;

bool validateString(string in){
    
   if(in.find("ecl") != std::string::npos && in.find("pid") != std::string::npos
        && in.find("eyr") != std::string::npos && in.find("hcl") != std::string::npos
        && in.find("byr") != std::string::npos && in.find("iyr") != std::string::npos
        && in.find("hgt") != std::string::npos){
            return true;
        }
    return false;
}



string removeNumbers(string str)
{
    int current = 0;
    for(int i = 0; i< str.length(); i++){
        if(!isdigit(str[i])){
            str[current] = str[i];
            current++;
        }
    }

    return str.substr(0,current);
}
string removeChars(string str)
{
    int current = 0;
    for(int i = 0; i< str.length(); i++){
        if(isdigit(str[i])){
            str[current] = str[i];
            current++;
        }
    }

    return str.substr(0,current);
}

string getKey(string str)
{
    int current = 0;
    for(int i = 0; i< str.length(); i++){
        if(str[i] != ':'){
            str[current] = str[i];
            current++;
        }
        else{
            break;
        }
    }

    return str.substr(0,current);
}
string getValue(string str)
{
    int current = 0;
    for(int i = 0; i< str.length(); i++){
        if(str[i - 1] != ':')
            current++;
        else
            break;
    }

    return str.substr(current, str.length());
}

bool match(string in){
    string key = getKey(in);
    string value = getValue(in);
    if(key == "byr"){
        int year = stoi(value);
        if(year >= 1920 && year <= 2002)
            return true;
        else
            return false;
    }
    else if(key == "iyr"){
        int year = stoi(value);
        if(year >= 2010 && year <= 2020)
            return true;
        else
            return false;
    }
    else if(key == "eyr"){
        int year = stoi(value);
        if(year >= 2020 && year <= 2030)
            return true;
        else
            return false;
    }
    else if(key == "hgt"){
        if(removeNumbers(value) == "cm"){
            int height = stoi(removeChars(in));

            if(height >= 150 && height <= 193)
                return true;
            else
                return false;
        }
        else if(removeNumbers(value) == "in"){
            int height = stoi(removeChars(in));

            if(height >= 59 && height <= 76)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else if(key == "ecl"){
        if(value =="amb" || value == "blu" || value == "brn" ||
            value == "gry" || value == "grn" || value =="hzl" || value == "oth")
            return true;
        else 
            return false;
    }

    else if(key == "pid"){

        if(value.length() == 9){
            
            for(int i = 0; i < value.length(); i++){
                if(isdigit(value[i]))
                    continue;
                else
                    return false;
            }
            return true;
        }
        else{
            return false;
        }
    }

    else if(key == "hcl"){
        if(value[0] == '#' && value.length() == 7){
            for(int i = 1; i < value.length(); i++){
                if(isxdigit(value[i]))
                    continue;
                else 
                    return false;
            }
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

int main(){
    string fileName = "input.in";

    ifstream inputFile(fileName);
    string input;
    vector<string> data;
    string builder;


    while(getline(inputFile, input)){
        if(input.empty()){
            data.push_back(builder);
            builder = "";
        }
        else
            builder += " " + input + " ";

    }
    int counter = 0;
    int counter2 = 0;
    int result = 0;
    int fieldCounter;
    string field;
    
    for(auto i : data){
       for(char const &c : i){
           if(c == ' '){
               if(match(field)){
                   counter2++;
                   cout << field << " is valid: "<< counter2 << endl;
               }
                
                field = "";
           }
           else{
               field += c;
           }
       }
       if(counter2 >= 7 && validateString(i) ){
            result++;
       }
       
        counter2 = 0;
    }
    
    
    cout <<  result << " ";

    return 0;

}