#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

vector<int> extractInts(string s){

    vector<int> result;
    for(auto c : s){
        int x = c - '0';
        result.push_back(x);
    }
    return result;
}

void print(vector<vector<int>> in){
    for(auto i : in){
        for(auto j : i){
            std::cout << j;
        }
        std::cout << endl;
    }
}

int calcSum(vector<vector<int>> in){
    int sum = 0;
    for(auto i : in){
        for(auto j : i){
            sum+=j;
        }
    }
    return sum;
}

// Set flashed to -1 and check it's neighbours, recursice call if neighbour is flashed
void flash(vector<vector<int>> &data, int row, int col, int &sum){
    sum++;
    data[row][col] = -1;

    /*
        |
        x
    */
    if(row != 0 && data[row-1][col]!=-1){
        data[row-1][col]++;
        if(data[row-1][col] > 9){
            flash(data, row-1, col, sum);
        }
    }
    /*
         /
        x
    */
    if(row != 0 && col != data[row].size()-1 && data[row-1][col+1]!=-1){
        data[row-1][col+1]++;
        if(data[row-1][col+1] > 9){
            flash(data, row-1, col+1, sum);
        }
    }

    /*
        x--
    */
    if(col != data[row].size()-1 && data[row][col+1]!=-1){
        data[row][col+1]++;
        if(data[row][col+1] > 9){
            flash(data, row, col+1, sum);
        }
    }

    /*
        x
         \
    */
    if(row != data.size()-1 && col != data[row].size()-1 && data[row+1][col+1]!=-1){
        data[row+1][col+1]++;
        if(data[row+1][col+1] > 9){
            flash(data, row+1, col+1, sum);
        }
    }

    /*
        x
        |
    */
    if(row != data.size() - 1 && data[row+1][col]!=-1){
        data[row+1][col]++;
         if(data[row+1][col] > 9){
            flash(data, row+1, col, sum);
        }
    }
    /*
        x
       /
    */

    if(row != data.size()-1 && col != 0 && data[row+1][col-1]!=-1){
        data[row+1][col-1]++;
        if(data[row+1][col-1] > 9){
            flash(data, row+1, col-1, sum);
        }
    }

    /*
        --x
    */
    if(col != 0 && data[row][col-1]!=-1){
        data[row][col-1]++;
        if(data[row][col-1] > 9){
            flash(data, row, col-1, sum);
        }
    }

    /*
       \
        x
    */
    if(row != 0 && col != 0 && data[row-1][col-1]!=-1){
        data[row-1][col-1]++;
        if(data[row-1][col-1] > 9){
            flash(data, row-1, col-1, sum);
        }
    }

    

    

    

    

    

    
}

void part1(vector<vector<int>> data){
    int sum = 0;

    for(int x = 0; x < 100; x++){
        for(int i = 0; i < data.size(); i++){
            for(int j = 0; j < data[i].size(); j++){
                // If element is -1 it has been flashed this iteration
                if(data[i][j]!= -1)
                    data[i][j]++;
                
        
                if(data[i][j] > 9){
                    flash(data, i, j, sum);
                }
            }
        }
        
        // Sets all flashed elements to 0 for next iteration
        for(int i = 0; i < data.size(); i++){
            for(int j = 0; j < data[i].size(); j++){
                if(data[i][j] == -1)
                    data[i][j] = 0;
            }
        }
    }
    std::cout <<"Result of part 1: " << sum << endl;
}

void part2(vector<vector<int>> data){
    int sum = 0;
    int firstSync;

    for(int x = 0; x < 500; x++){
        for(int i = 0; i < data.size(); i++){
            for(int j = 0; j < data[i].size(); j++){
                if(data[i][j]!= -1)
                    data[i][j]++;
                
        
                if(data[i][j] > 9){
                    flash(data, i, j, sum);
                }
            }
        }

        for(int i = 0; i < data.size(); i++){
            for(int j = 0; j < data[i].size(); j++){
                if(data[i][j] == -1)
                    data[i][j] = 0;
            }
        }

        // If all of our elements are 0, we get the current step and break
        int accumulatedSum = calcSum(data);
        if(accumulatedSum == 0){
            firstSync = x+1;
            break;
        }
    }

    std::cout << "Result of part 2: " << firstSync;
}

int main(){

    vector<vector<int>> data;

     // Data prep
    string fileName = "input.in";

    ifstream inputFile(fileName);
    string input;

    while(getline(inputFile, input)){
        data.push_back(extractInts(input));
    }

    part1(data);
    part2(data);
    
}