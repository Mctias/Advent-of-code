#include<iostream>
#include<unordered_map>
#include<set>
#include<string>
#include<fstream>
#include<vector>
#include <functional>
#include <utility>


using namespace std;



// This hashing funciton isn't the best but it works for now
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;  
    }
};

void part1(vector<string> data){
    // Part 1

    // Rules setup

    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    set<string> forbidden = {"ab", "cd", "pq", "xy"};

    // Find nice strings

    int niceStrings = 0;

    for(int i = 0; i < data.size(); i++){
        int nVowels = 0;
        bool enoughVowels = false;
        bool twiceInARow = false;
        bool notForbidden = false;

        for(int j = 0; j < data[i].length(); j++){

            // Find all vowels
            if(vowels.find(data[i][j]) != vowels.end()){
                nVowels++;
            }
            
            // We have enough vowels
            if(nVowels >= 3){
                enoughVowels = true;

            }

            string tmp = "";

            tmp += data[i][j];
            tmp += data[i][j+1];

            // Check if any pair is forbidden
            if(forbidden.find(tmp) != forbidden.end()){
                notForbidden = false;
                break;
            }
                
            else{
                notForbidden = true;
            }
            
            // Check if we have a pair with the same chars
            if(data[i][j] == data[i][j+1])
                twiceInARow = true;
        }

        // If all conditions are met we have a nice string
        if(enoughVowels && notForbidden && twiceInARow){
            niceStrings++;
        }
    }

    cout << niceStrings << endl;
}

void part2(vector<string> data){
    unordered_map<pair<char, char>, int, pair_hash> pairs;

    int niceStrings = 0;
    
    for(int i = 0; i < data.size(); i++){
        bool goodPair = false;
        bool goodRepeat = false;
        
        for(int j = 0; j < data[i].length(); j++){

            pair<char, char> currentPair = make_pair(data[i][j], data[i][j+1]);

            // Look for already existing pair
            if(pairs.find(currentPair) != pairs.end() ){

                // No overlaps
                if(pairs[currentPair] != j-1)
                    goodPair = true;
            }

            // If not found we insert it to our table
            else{
                pairs[currentPair] = j;
            }
            
            // Look for a repeat
            if(data[i][j] == data[i][j+2])
                goodRepeat = true;
        }

        // Cleanup
        pairs.clear();

        // If all conditions are met we have a nice string

        if(goodPair && goodRepeat){
            niceStrings++;
        }
    }

    cout << niceStrings;
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


    part1(data);
    part2(data);
    


}