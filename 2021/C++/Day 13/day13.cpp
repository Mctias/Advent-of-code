#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;



int CS = 1311;
int RS = 895;

int grid[895][1311] = {{0}};

vector<int> extractInts(string s){
    vector<int> result;
    string word = "";

    for(auto c : s){
        if(c == ',' || c== ' '){
            result.push_back(stoi(word));
            word = "";
        }
        else{
            word+=c;
        }
    }

    return result;
}

void printGrid(int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void setZero(){
    for(int i = 0; i <= RS; i++){
        for(int j = 0; j < CS; j++){
            grid[i][j] = 0;
        }
    }
}

void foldX(int y, int r, int c){
    // Counts the number of cols after y
    int counter = 0;
    for(int row = 0; row < r; row++){
        counter = 0;
        for(int col = y; col < c; col++){
            if(col > y)
                counter++;

            if(col > y){
                if(grid[row][col] == 1){
                    // The insert position is row, y - number of cols since y
                    int insertCol = y - counter;
                    grid[row][insertCol] = 1;
                }
            }
        }
    }

    // We half the number of cols
    CS = floor((CS-1)/2);
    
}

void foldY(int x, int r, int c){
    // Counts the number of rows after x
    int counter = 0;
    for(int row = x; row < r; row++){
        if(row > x)
            counter++;
        for(int col = 0; col < c; col++){
            if(row > x){
                if(grid[row][col] == 1){
                    // The insert position is x - number of rows since x , col
                    int insertRow = x - counter;
                    grid[insertRow][col] = 1;
                }
            }
        }
    }

    // We half the number of rows
    RS = floor((RS-1)/2);
}

void countOnes(int r, int c){
    int counter = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 1)
                counter++;
        }
    }

    cout << endl << "Part 1: " <<  counter << endl;
}

int main(){

    setZero();
    vector<vector<int>> points;

     // Data prep
    string fileName = "points.in";
    ifstream inputFile(fileName);
    
    string input;

    while(getline(inputFile, input)){
        points.push_back(extractInts(input));
    }

    for(int i = 0; i < points.size(); i++){
        //cout << points[i][0] << " " << points[i][1] << endl;
        grid[points[i][1]][points[i][0]] = 1;
    }
    
    // Folds
    foldX(655, RS, CS);

    countOnes(RS, CS);

    foldY(447, RS, CS);
    foldX(327, RS, CS);
    foldY(223, RS, CS);
    foldX(163, RS, CS);
    foldY(111, RS, CS);
    foldX(81, RS, CS);
    foldY(55, RS, CS);
    foldX(40, RS, CS);
    foldY(27, RS, CS);
    foldY(13, RS, CS);
    foldY(6, RS, CS);
    
    printGrid(RS, CS);

    cout << "Part 2: AHGCPGAU" << endl;
}