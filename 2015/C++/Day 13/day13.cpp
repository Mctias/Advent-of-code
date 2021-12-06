#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

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

vector<string> tokenize(string& s){
    string word = "";
    vector<string> result;

    for(auto c : s){
        if(c == ' ' || c == '.'){
            result.push_back(word);
            word = "";
        }
        else{
            word+=c;
        }
    }
    return result;
}

void buildInitialHash(unordered_map<string, int>& nameIndxRel){

    nameIndxRel["Alice"] = 0;
    nameIndxRel["Bob"] = 1;
    nameIndxRel["Carol"] = 2;
    nameIndxRel["David"] = 3;
    nameIndxRel["Eric"] = 4;
    nameIndxRel["Frank"] = 5;
    nameIndxRel["George"] = 6;
    nameIndxRel["Mallory"] = 7;
    nameIndxRel["Me"] = 8;
}

void buildHappinesHash(unordered_map<string, int>& nameIndxRel, unordered_map<pair<int,int>, int, pair_hash>& happinessRel, vector<string> data){

    for(auto x : data){
        vector<string> splitString = tokenize(x);
        string leftName = splitString[0];
        string rightName = splitString[splitString.size() - 1];
        string gainOrLose = splitString[2];
        int happiness = stoi(splitString[3]);

        int idx1 = nameIndxRel[leftName];
        int idx2 = nameIndxRel[rightName];

        if(gainOrLose == "lose")
            happiness *= -1;
        
        happinessRel[make_pair(idx1, idx2)] = happiness;
    }

    for(int i = 0; i < 8; i++){
        happinessRel[make_pair(i, 8)] = 0;
        happinessRel[make_pair(8, 1)] = 0;
    }
}

// Build possible table order
vector<int> buildTableOrder(int a[], int n)
{
    vector<int> vec;
    for(int i = 0; i < n; i++){
        vec.push_back(a[i]);
    }

    return vec;
}
  
// Function to find the permutations
// Which is all the possible ways we can travel
// (There's a lot)
vector<vector<int>> findPermutations(int a[], int n)
{   
    vector<vector<int>> result;
  
    // Sort the given array
    sort(a, a + n);
  
    // Find all possible permutations
    do {
        result.push_back(buildTableOrder(a, n));
    } while (next_permutation(a, a + n));

    return result;
}


int findTotalHappiness(vector<int> seating, unordered_map<pair<int,int>, int, pair_hash> happinessRel){

    int happiness = 0;

    for(int i = 0; i < seating.size() - 1; i++){

        int leftToRight = happinessRel[make_pair(seating[i], seating[i+1])];
        int rightToLeft = happinessRel[make_pair(seating[i+1], seating[i])];

        happiness += (leftToRight + rightToLeft);
    }

    return happiness;

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

    unordered_map<string, int> nameIndxRel;
    unordered_map<pair<int,int>, int, pair_hash> happinessRel;

    buildInitialHash(nameIndxRel);
    buildHappinesHash(nameIndxRel, happinessRel, data);

    int people[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    int n = sizeof(people) / sizeof(people[0]);

    vector<vector<int>> perm = findPermutations(people, n);

    vector<int> happinessAllSeatings;

    for(auto i : perm){
        i.push_back(i[0]);
        happinessAllSeatings.push_back(findTotalHappiness(i, happinessRel));
    }

    //happinessAllSeatings.push_back(findTotalHappiness(test, happinessRel));

    int maxHappiness = *max_element(happinessAllSeatings.begin(), happinessAllSeatings.end());

    cout << maxHappiness;
    

}