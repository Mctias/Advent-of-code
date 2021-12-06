// Not the best code/solution... but it works..?
// Could have been made better with regex and recursion
// I love hash maps

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<unordered_map>
#include<sstream>

using namespace std;

vector<string> splitString(string s){
    vector<string> result;
    istringstream ss(s);
    string word; 

    while (ss >> word) 
    {
        result.push_back(word);
    }
    return result;
}

void createHashTable(vector<string> data, unordered_map<string, unsigned short> &umap){


    for(auto i : data){
       vector<string> partials =  splitString(i);

        if(partials.size() == 3){
            if(umap.find(partials[2]) == umap.end()){
                umap[partials[2]] = 0;
            }
        }

        else if(partials.size() == 4){
            if(umap.find(partials[1]) == umap.end()){
                umap[partials[1]] = 0;
            }

            if(umap.find(partials[3]) == umap.end()){
                umap[partials[3]] = 0;
            }
        }

        else if(partials.size() == 5 && !(partials[1] == "LSHIFT" || partials[1] == "RSHIFT")){ 
            if(umap.find(partials[0]) == umap.end()){
                umap[partials[0]] = 0;
            }

            if(umap.find(partials[2]) == umap.end()){
                umap[partials[2]] = 0;
            }

            if(umap.find(partials[4]) == umap.end()){
                umap[partials[4]] = 0;
            }
        }

        else if(partials.size() == 5 && (partials[1] == "LSHIFT" || partials[1] == "RSHIFT")){ 
            if(umap.find(partials[0]) == umap.end()){
                umap[partials[0]] = 0;
            }

            if(umap.find(partials[4]) == umap.end()){
                umap[partials[4]] = 0;
            }
        }

    }
    
}

void solution(vector<string> data, unordered_map<string, unsigned short> &umap){
    
    for(auto i : data){        
        vector<string> partials = splitString(i);
        
        if(partials.size() == 3){
            if(isdigit(partials[0][0]))
                umap[partials[2]] = stoi(partials[0]);
            else
                umap[partials[2]] = umap[partials[0]];
        }
    
        if(partials[1] == "LSHIFT"){
            int value = umap[partials[0]] << stoi(partials[2]);
            umap[partials[4]] = value;
        }

        if(partials[1] == "RSHIFT"){
            int value = umap[partials[0]] >> stoi(partials[2]);
            umap[partials[4]] = value;
        }

        if(partials[1] == "AND"){
            if(!isdigit(partials[0][0])){
                int value = umap[partials[0]] & umap[partials[2]];
                umap[partials[4]] = value;
            }
            else{
                int value = stoi(partials[0]) & umap[partials[2]];
                umap[partials[4]] = value;
            }
        }

        if(partials[1] == "OR"){
            int value = umap[partials[0]] | umap[partials[2]];
            umap[partials[4]] = value;
        }

        if(partials[0] == "NOT"){
            int value = ~umap[partials[1]];
            umap[partials[3]] = value;
        }
    }
}

int main(){
    // Data prep
    string filename = "input.in";
    fstream inputFile(filename);

    string in;
    vector<string> data;

    while(getline(inputFile, in)){
        data.push_back(in);
    }

    unordered_map<string, unsigned short> umap;

    createHashTable(data, umap);

    // This could probably have been done better with recursion... :)
    // Kinda dumb to recalculate a bunch of stuff but you know
    for(int i = 0; i < data.size(); i++){
        solution(data, umap);
    }

    unsigned short firstResult =  umap["a"];

    cout << firstResult << endl;

    
    // Part two was the same logic as first part so didn't create a function
    // If you want the result of the second part, replace the 44430 on row 4 in the input with
    // 3176 (result of first part)
}