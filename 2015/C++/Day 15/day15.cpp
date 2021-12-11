#include<iostream>
#include<vector>
#include<numeric>
#include <functional>
#include <algorithm>

using namespace std;

// Amazing solution of four very effectice loops, the least number of loops ever accuired /s

int part1(){

    vector<int> sprinkles = {5, -1, 0, 0};
    vector<int> peanutButter = {-1, 3, 0, 0};
    vector<int> frosting = {0, -1, 4, 0};
    vector<int> sugar = {-1, 0, 0, 2};

    int initalProduct = 1;


    int maximum = INT_MIN;

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= 100; k++){
                for(int l = 1; l <= 100; l++){

                    if((i + j + k + l) != 100)
                        continue;
                    long long currSum = 0;

                    int capacity = i * sprinkles[0] + j * peanutButter[0] + k * frosting[0] + l * sugar[0];
                    int durability = i * sprinkles[1] + j * peanutButter[1] + k * frosting[1] + l * sugar[1];
                    int flavor = i * sprinkles[2] + j * peanutButter[2] + k * frosting[2] + l * sugar[2];
                    int texture = i * sprinkles[3] + j * peanutButter[3] + k * frosting[3] + l * sugar[3];

                    capacity = max(capacity, 0);
                    durability = max(durability, 0);
                    flavor = max(flavor, 0);
                    texture = max(texture, 0);

                    currSum += capacity * durability * flavor * texture;

                    if(currSum > maximum){
                        maximum = currSum;
                    }
                }
            }
        }
    }

    return maximum;

}

int part2(){

    vector<int> sprinkles = {5, -1, 0, 0, 5};
    vector<int> peanutButter = {-1, 3, 0, 0, 1};
    vector<int> frosting = {0, -1, 4, 0, 6};
    vector<int> sugar = {-1, 0, 0, 2, 8};

    int initalProduct = 1;

    int maximum = INT_MIN;

    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            for(int k = 1; k <= 100; k++){
                for(int l = 1; l <= 100; l++){

                    if((i + j + k + l) != 100)
                        continue;

                    long long currSum = 0;

                    int capacity = i * sprinkles[0] + j * peanutButter[0] + k * frosting[0] + l * sugar[0];
                    int durability = i * sprinkles[1] + j * peanutButter[1] + k * frosting[1] + l * sugar[1];
                    int flavor = i * sprinkles[2] + j * peanutButter[2] + k * frosting[2] + l * sugar[2];
                    int texture = i * sprinkles[3] + j * peanutButter[3] + k * frosting[3] + l * sugar[3];
                    int calories = i * sprinkles[4] + j * peanutButter[4] + k * frosting[4] + l * sugar[4];

                    if(calories != 500)
                        continue;

                    capacity = max(capacity, 0);
                    durability = max(durability, 0);
                    flavor = max(flavor, 0);
                    texture = max(texture, 0);

                    currSum += capacity * durability * flavor * texture;


                    if(currSum > maximum){
                        maximum = currSum;
                    }
                }
            }
        }
    }

    return maximum;

}

int main(){

    cout << part1() << endl;
    cout << part2() << endl;    
}