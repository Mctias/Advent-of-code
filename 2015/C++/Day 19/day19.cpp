#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<set>

using namespace std;

pair<string, string> splitString(string s){

    string word = "";
    vector<string> words;
    pair<string, string> result;

    for(auto c : s){
        if(c == ' '){
            words.push_back(word);
            word = "";
        }
        else{
            word += c;
        }
    }

    result.first = words[0];
    result.second = words[1];

    return result;
}

int main(){

    string in;

    string filename = "input.in";

    ifstream input_file(filename);

    vector<pair<string, string>> data;

    while(getline(input_file, in)){
        data.push_back(splitString(in));
    }

    set<string> resMols;
    string inMol = "CRnCaSiRnBSiRnFArTiBPTiTiBFArPBCaSiThSiRnTiBPBPMgArCaSiRnTiMgArCaSiThCaSiRnFArRnSiRnFArTiTiBFArCaCaSiRnSiThCaCaSiRnMgArFYSiRnFYCaFArSiThCaSiThPBPTiMgArCaPRnSiAlArPBCaCaSiRnFYSiThCaRnFArArCaCaSiRnPBSiRnFArMgYCaCaCaCaSiThCaCaSiAlArCaCaSiRnPBSiAlArBCaCaCaCaSiThCaPBSiThPBPBCaSiRnFYFArSiThCaSiRnFArBCaCaSiRnFYFArSiThCaPBSiThCaSiRnPMgArRnFArPTiBCaPRnFArCaCaCaCaSiRnCaCaSiRnFYFArFArBCaSiThFArThSiThSiRnTiRnPMgArFArCaSiThCaPBCaSiRnBFArCaCaPRnCaCaPMgArSiRnFYFArCaSiThRnPBPMgAr";

    for(int i = 0; i < inMol.length(); i++){
        for(auto j : data){
            string newMol = inMol;
            if(string(1, inMol[i]) == j.first){
                newMol.erase(newMol.begin() + i);
                newMol.insert(i, j.second);
                //cout << newMol << endl;
                resMols.insert(newMol);
            }

            else if((string() + inMol[i] + inMol[i+1]) == j.first){
                cout << string() + inMol[i] + inMol[i+1] << endl;
                newMol.erase(newMol.begin() + i);
                newMol.erase(newMol.begin() + i);
                newMol.insert(i, j.second);
                //cout << newMol << endl;
                resMols.insert(newMol);
            }
        }
    }

    cout << resMols.size();

    while(inMol != "e"){
        for(int i = 0; i < inMol.length(); i++){
            for(auto j : data){
                if(string(1, inMol[i]) == j.second){
                    inMol.erase(inMol.begin() + i);
                    inMol.insert(i, j.first);
                }

                else if((string() + inMol[i] + inMol[i+1]) == j.second){
                    inMol.erase(inMol.begin() + i);
                    inMol.erase(inMol.begin() + i);
                    inMol.insert(i, j.first);
                }
            }
    }
        
    }


}