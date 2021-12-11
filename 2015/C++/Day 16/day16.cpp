#include<iostream>
#include<unordered_map>
#include <fstream>
#include<vector>
#include<string>

using namespace std;

vector<string> splitString(string s){

    string word = "";
    vector<string> result;

    for(auto c : s){

        if((c == ' ' || c == ':' || c == ',') && word != ""){
            result.push_back(word);
            word = "";
        }
        else{
            if(c != ' ')
                word += c;
        }
    }
    

    return result;
}

int main(){

    unordered_map<string, int> memories;

    memories["children"] = 3;
    memories["cats"] = 7;
    memories["samoyeds"] = 2;
    memories["pomeranians"] = 3;
    memories["akitas"] = 0;
    memories["vizslas"] = 0;
    memories["goldfish"] = 5;
    memories["trees"] = 3;
    memories["cars"] = 2;
    memories["perfumes"] = 1;

    string in;

    string filename = "input.in";

    ifstream input_file(filename);

    vector<vector<string>> data;

    while(getline(input_file, in)){
        data.push_back(splitString(in));
    }


    for(int i = 0; i < data.size(); i++){
        string firstThing = data[i][2];
        string secondThing = data[i][4];
        string thirdThing = data[i][6];

        int firstParameter = stoi(data[i][3]);
        int secondParameter = stoi(data[i][5]);
        int thirdParameter = stoi(data[i][7]);

        

        if(firstThing == "cats" || firstThing == "trees"){
            if(memories[firstThing] >= firstParameter)
                continue;
        }
        else if(firstThing == "pomeranians" || firstThing == "goldfish"){
            if(memories[firstThing] <= firstParameter)
                continue;
        }
        else{
            if(memories[firstThing] != firstParameter)
                continue;
        }


        if(secondThing == "cats" || secondThing == "trees"){
            if(memories[secondThing] >= secondParameter)
                continue;
        }
        else if(secondThing == "pomeranians" || secondThing == "goldfish"){
            if(memories[secondThing] <= secondParameter)
                continue;
        }
        else{
            if(memories[secondThing] != secondParameter)
                continue;
        }


        if(thirdThing == "cats" || thirdThing == "trees"){
            if(memories[thirdThing] >= thirdParameter)
                continue;
        }
        else if(thirdThing == "pomeranians" || thirdThing == "goldfish"){
            if(memories[thirdThing] <= thirdParameter)
                continue;
        }
        else{
            if(memories[thirdThing] != thirdParameter)
                continue;
        }
        
        


      
        


        cout << data[i][1] << endl;
    
 
    }

   




}