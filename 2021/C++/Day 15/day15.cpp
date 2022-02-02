#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<math.h>
#include <queue>
#include<unordered_map>
#include <algorithm>

using namespace std;
#define V 100
typedef pair<int, int> iPair;
  

int mat[100][100];

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;  
    }
};

unordered_map<pair<int,int>, int, pair_hash> umap;

vector<int> extractInts(string s){
    vector<int> result;

    for(auto c : s){
        result.push_back(c - '0');
    }

    return result;
}



int solve(int r, int c){

    if(r < 0 || r >= V || c < 0 || c >= V){
        return INT_MAX;
    }

    if(umap.find(make_pair(r,c)) != umap.end()){
        return umap[make_pair(r,c)];
    }

    if(r == V - 1 && c == V - 1){
        return mat[r][c];
    }

    int ans = mat[r][c] + min({solve(r+1, c), solve(r, c+1)});
    umap[make_pair(r,c)]  = ans;
    return ans;
    
}




int main(){
    vector<vector<int>> grid;

     // Data prep
    string fileName = "input.in";
    ifstream inputFile(fileName);
    
    string input;

    while(getline(inputFile, input)){
        grid.push_back(extractInts(input));
    }


    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            mat[i][j] = grid[i][j];
        }
    }

    cout << solve(0, 0) - mat[0][0] << endl;
    
}