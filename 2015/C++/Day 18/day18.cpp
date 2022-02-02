#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

#define ROWS 102
#define COLS 102

vector<char> extractChars(string s){
    vector<char> result;

    result.push_back('I');

    for(auto c : s){
        result.push_back(c);
    }

    result.push_back('I');

    return result;
}

void print(char mat[ROWS][COLS]){
    for(int i = 0; i < sizeof(mat[0]); i++){
        for(int j = 0; j < sizeof(mat[0]); j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void solve(char mat[ROWS][COLS]){

    char copy[ROWS][COLS];

    for(int r = 0; r < sizeof(mat[0]) ; r++){
        for(int c = 0; c < sizeof(mat[0]); c++){
            copy[r][c] = mat[r][c];
        }
    }

    for(int r = 1; r < sizeof(mat[0]) - 1; r++){
        for(int c = 1; c < sizeof(mat[0]) - 1; c++){

            if((r == 1 && c == 1) || (r == 1 && c == COLS-2) || (r == ROWS - 2 && c == 1) || (r == ROWS - 2 && c == COLS - 2))
                continue;
            
            int sum = 0;

            // Check neighbours

            if(mat[r-1][c] == '#' || mat[r-1][c] == 'X'){
                sum++;
            }
            if(mat[r-1][c+1] == '#' || mat[r-1][c+1] == 'X'){
                sum++;
            }
            if(mat[r][c+1] == '#' || mat[r][c+1] == 'X'){
                sum++;
            }
            if(mat[r+1][c+1] == '#' || mat[r+1][c+1] == 'X' ){
                sum++;
            }
            if(mat[r+1][c] == '#' || mat[r+1][c] == 'X'){
                sum++;
            }
            if(mat[r+1][c-1] == '#' || mat[r+1][c-1] == 'X'){
                sum++;
            }
            if(mat[r][c-1] == '#' || mat[r][c-1] == 'X'){
                sum++;
            }
            if(mat[r-1][c-1] == '#' || mat[r-1][c-1] == 'X' ){
                sum++;
            }

            if(mat[r][c] == '#'){
                if(sum == 2 || sum == 3){
                    copy[r][c] = '#';
                }
                else{
                    copy[r][c] = '.';
                }
            }
            else if(mat[r][c] == '.'){
                if(sum == 3){
                    copy[r][c] = '#';
                }
                else{
                    copy[r][c] = '.';
                }
            }
        }
    }

    for(int r = 0; r < sizeof(mat[0]) ; r++){
        for(int c = 0; c < sizeof(mat[0]); c++){
            mat[r][c] = copy[r][c];
        }
    }

}

int count(char mat[ROWS][COLS]){

    int sum = 0;

    for(int i = 0; i < sizeof(mat[0]); i++){
        for(int j = 0; j < sizeof(mat[0]); j++){
            if(mat[i][j] == '#' || mat[i][j] == 'X')
                sum++;
        }
    }
    return sum;
}

int main (){

    vector<vector<char>> grid;
    vector<char> padd;

    for(int i = 0; i < ROWS; i++)
        padd.push_back('I');

    grid.push_back(padd);

     // Data prep
    string fileName = "input.in";
    ifstream inputFile(fileName);
    
    string input;

    while(getline(inputFile, input)){
        grid.push_back(extractChars(input));
    }

    grid.push_back(padd);

    char mat[ROWS][COLS];


    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            mat[i][j] = grid[i][j];
        }
    }

    mat[1][1] = 'X';
    mat[1][COLS-2] = 'X';
    mat[ROWS-2][COLS-2] = 'X';
    mat[ROWS-2][1] = 'X';

    
    int steps = 100;

    for(int i = 0; i < steps; i++){
        solve(mat);
    }
    print(mat);
    cout << count(mat);
}