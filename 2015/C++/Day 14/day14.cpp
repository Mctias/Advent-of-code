#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>

using namespace std;

vector<int> extractInts(string s){
    stringstream ss;
    vector<int> result;

    ss << s;

    string tmpStr;
    int tmpInt;

    while(!ss.eof()){
        ss >> tmpStr;

        if(stringstream(tmpStr) >> tmpInt){
            result.push_back(tmpInt);
        }
        tmpStr = "";
    }
    return result;

}

// Part 1
int calcDistance(vector<int> conf){

    int sum = 0;
    int s = 0;
    int stopTime = 2503;

    int speed = conf[0];
    int travelTime = conf[1];
    int restTime = conf[2];

    for(int i = 0; i < stopTime; i++){

        if(s % travelTime == 0 && s != 0){
            i += restTime - 1;
            s = 0;
            continue;
        }  
        s++;
        sum += speed;
    }
    return sum;
}

// Part 2
vector<int> calcDistancesEverySecond(vector<int> conf){

    int sum = 0;
    int s = 0;
    int stopTime = 2503;
    int restCounter = 0;

    vector<int> distancesEverySecond;

    int speed = conf[0];
    int travelTime = conf[1];
    int restTime = conf[2];

    for(int i = 0; i < stopTime; i++){

        
        if(s % travelTime == 0 && s != 0){
            restCounter++;
            s = 0;
            distancesEverySecond.push_back(sum);
            continue;
        } 

        if(restCounter % restTime == 0){
            restCounter = 0;
        }
        else{
            restCounter++;
        }

        if(restCounter == 0)
        {
            sum += speed;
            s++;
        }
        distancesEverySecond.push_back(sum);
    }
    return distancesEverySecond;
}

int calcMaxPoints(vector<vector<int>> distances){

    int points[8] = {0};

    for(int i = 0; i < distances[0].size(); i++){
        int winner;
        vector<int> winningIdx;
        int tmp = INT_MIN;

        for(int j = 0; j < distances.size(); j++){

            if(distances[j][i] > tmp){
                tmp = distances[j][i];
                winner = j;
                winningIdx.clear();
            }
            else if(distances[j][i] == tmp){
                winningIdx.push_back(j);
            }
        }
        winningIdx.push_back(winner);
        
        for(int j= 0; j < winningIdx.size(); j++)
            points[winningIdx[j]]++;
        
    }

    return *max_element(begin(points), end(points));

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

    //Part 1
    vector<vector<int>> conf ;

    for(auto i : data){
        conf.push_back(extractInts(i));
    }

    vector<int> distances;

    for(auto i : conf){
        distances.push_back(calcDistance(i));
    }

    int maxLength = *max_element(distances.begin(), distances.end());

    cout << "Maximum distance: "<< maxLength << endl;

    // Part 2
    vector<vector<int>> distancesMatrix;

    for(auto i : conf){
        distancesMatrix.push_back(calcDistancesEverySecond(i));
    }

    int res = calcMaxPoints(distancesMatrix);

    cout << "Maximum score: " << res;
}