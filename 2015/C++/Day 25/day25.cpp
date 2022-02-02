#include<iostream>
#include<vector>

using namespace std;
#define ROW 5
#define COL 4

long long arr[3500][3500] = {0};
int M[ROW][COL] = { { 1, 2, 3, 4 },
                        { 5, 6, 7, 8 },
                        { 9, 10, 11, 12 },
                        { 13, 14, 15, 16 },
                        { 17, 18, 19, 20 }};

int main(){

    int codeRow = 3010;
    int codeCol = 3019;


    int row = 1;
    int col = 1;

    long long code = 20151125;

    while((row != codeRow) || (col != codeCol)){
        code = (code * 252533) % 33554393;

        if(row == 1){
            row = col + 1;
            col = 1;
        }
        else{
            col++;
            row--;
        }
    }

    cout << code;

}