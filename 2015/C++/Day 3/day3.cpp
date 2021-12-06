#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<set>
#include<unordered_map>
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

void part1(string data){
     // Part 1 

    unordered_map<pair<int,int>, int, pair_hash> houses; 

    int x = 0;
    int y = 0;

    for(int i = 0; i < data.length(); i++){
        if(data[i] == '<')
            x--;
        else if(data[i] == '>')
            x++;
        else if(data[i] == '^')
            y++;
        else if(data[i] == 'v')
            y--;

        if(houses.find(make_pair(x,y)) != houses.end()){
            houses[make_pair(x,y)]++;
        }
        else{
            houses[make_pair(x,y)] = 0;
        }
    }

    cout << houses.size() << endl;
}

void part2(string data){
     // Part 2, could make this prettier :)

    unordered_map<pair<int,int>, int, pair_hash> houses; 
   
    int x = 0;
    int y = 0;

    int roboX = 0;
    int roboY = 0;

    bool robot = false;

    for(int i = 0; i < data.length(); i++){
        
        if(!robot){
            if(data[i] == '<')
                x--;
            else if(data[i] == '>')
                x++;
            else if(data[i] == '^')
                y++;
            else if(data[i] == 'v')
                y--;

            if(houses.find(make_pair(x,y)) != houses.end()){
                houses[make_pair(x,y)]++;
            }
            else{
                houses[make_pair(x,y)] = 0;
            }
        }

        else{
            if(data[i] == '<')
                roboX--;
            else if(data[i] == '>')
                roboX++;
            else if(data[i] == '^')
                roboY++;
            else if(data[i] == 'v')
                roboY--;
            
            if(houses.find(make_pair(roboX,roboY)) != houses.end()){
                houses[make_pair(roboX,roboY)]++;
            }
            else{
                houses[make_pair(roboX,roboY)] = 0;
            }
        }

        robot = !robot;
    }
    cout << houses.size();
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

    part1(data);
    part2(data);
}