#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<unordered_map>
#include <numeric>
#include <functional>
 

using namespace std;

// Print board
void print(vector<vector<int>> board){
    for(auto i : board){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Get the numbers for the boards
vector<int> extractInts(string s){
    
    string word;
    vector<int> result;

    for(auto c : s){
        if(c == ' '){
            result.push_back(stoi(word));
            word="";
        }
        else{
            word+=c;
        }
    }

    return result;
}

//Check if a board has bingo
bool hasBingo(vector<vector<int>> board){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){

            if(board[i][j] != -1) continue;

            if(j == 0){
                if(board[i][j+1] == -1 && board[i][j+2] == -1 
                    && board[i][j+3] == -1 && board[i][j+4] == -1){
                    return true;
                }
            }
            
            if(i == 0){
                if(board[i+1][j] == -1 && board[i+2][j] == -1 
                    && board[i+3][j] == -1 && board[i+4][j] == -1){
                    return true;
                }
            }
        }
    }
    return false;
}

//Calculates the sum of the numbers that hasn't been marked
int calculateSum(vector<vector<int>> board){

    int result = 0;
    for(auto i : board){
        for(auto j : i){
            if(j != -1)
                result += j;
        }
    }
    return result;
}

//Plays the bingo. Marks the board with -1 if the number has been found and checks if it has bingo
vector<int> play(vector<vector<int>> board, vector<int> sequence){

    vector<int> result;
    
    for(int i = 0; i < sequence.size(); i++){
        for(int j = 0; j < board.size(); j++){
            for(int k = 0; k < board[j].size(); k++){

                if(board[j][k] == sequence[i]){
                    board[j][k] = -1;
                    //print(board);
                }
                if(i >= 5 && hasBingo(board)){
                    //Has bingo after i numbers
                    result.push_back(i);

                    int sum = calculateSum(board) * sequence[i];
                    result.push_back(sum);
                    return result;
                }
            }
        }
    }
    return result;
}

int main(){
    
    // Data prep - Read the sequence from input1.in and the boards from input2.in
    string fileName1 = "input1.in";
    string fileName2 = "input2.in";

    ifstream inputFile1(fileName1);
    ifstream inputFile2(fileName2);
    
    int input1;
    string input2;

    vector<int> seq;
    vector<vector<int>> board;

    while(inputFile1 >> input1){
        seq.push_back(input1);
    }

    //Just have this to see the board at the end, not really needed but is nice
    unordered_map<int, vector<vector<int>>> boards;
    int index = 0;

    //The results of the boards
    vector<vector<int>> results;

    //Main logic - Plays every board until it has bingo and saves the numbers required 
    //Then the lowest/highest numbers are used to find the answers
    while(getline(inputFile2, input2)){
        //If we're at an empty line we have a complete board so we play it then delete it
        if(input2.length() == 0 || input2.length() == 1){
            //print(board);
            boards[index] = board;
            index++;
            results.push_back(play(board, seq));
            board.clear();
        }
        else{
            board.push_back(extractInts(input2));
        }

    }

    //Part 1 - We find the vector with the least numbers required to win, which contains the rest of our winners data

    int min = INT_MAX;
    int winner;
    int sum;

    for(int i = 0; i < results.size(); i++){
        
        if(results[i][0] < min){
            min = results[i][0];
            winner = i;
            sum = results[i][1];
        }
    }
    cout << "----------------Part 1----------------" << endl << endl;
    cout << "The winner is board number: " << winner << " with " << min << " draws!" << endl;
    cout << "The sum was: " << sum << endl << endl;

    print(boards[winner]);

    
   cout << "----------------Part 2----------------" << endl << endl;

    // Part 2 - Same logic but we find the max instead

    int max = INT_MIN;
    int loser;

    for(int i = 0; i < results.size(); i++){
        
        if(results[i][0] > max){
            max = results[i][0];
            loser = i;
            sum = results[i][1];
        }
    }
    cout << "The worst board is board number: " << loser << " with " << max << " draws!" <<endl;
    cout << "The sum was: " << sum << endl << endl;

    print(boards[loser]);
}