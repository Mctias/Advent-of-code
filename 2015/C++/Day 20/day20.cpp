#include<iostream>
#include <stdio.h>
#include<math.h>

using namespace std;

int sum_of_presents_1(int n) {
    int sum = 0;
    int d = (int)sqrt((double)n) + 1;
    cout << d << endl;
    for (int i=1; i<=d; i++) {
        if (n % i == 0) {
            sum += i;
            sum += n/i;
        }
    }
    return sum*10;
}

int sum_of_presents_2(int n) {
    int sum = 0;
    int d = (int)sqrt((double)n) + 1;
    for (int i=1; i<=d; i++) {
        if (n % i == 0) {
            if( i <= 50) {
                sum += n/i;
            }
            if (n/i <= 50) {
                sum += i;
            }
        }
        
    }
    return sum*11;
}


int main(){

    int presents = 34000000;
    int n = 1;


    while(sum_of_presents_1(n) < presents){
        n++;
    }

    cout << n;
    

}