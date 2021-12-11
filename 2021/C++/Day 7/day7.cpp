#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

double findMedian(vector<int> data){
    sort(data.begin(), data.end());

    int size = data.size();

    if(size % 2 != 0)
        return (double)data[size / 2];
    return (double)(data[(size - 1) / 2] + data[size / 2]) / 2; 
}


void part1_median(vector<int> data){

    int median = findMedian(data);
    int sum;

    for(int i = 0; i < data.size(); i++){
        if(data[i] > median)
            sum += data[i] - median;
        else
            sum += median - data[i];
    }

    cout << "Part 1 using the median: " << sum << endl;
}

void part2_brute(vector<int> data){
    
    vector<int> results;

     // Brute force :)
    for(int i = 0; i < data.size(); i++){
        int sum = 0;

        for(int j = 0; j < data.size(); j++){
            if(data[j] <= data[i]){
                int counter = 0;
                for(int k = data[j]; k < data[i]; k++){
                    counter++;
                    sum += counter;
                }
            }
            else{
                int counter = 0;
                for(int k = data[i]; k < data[j]; k++){
                    counter++;
                    sum += counter;
                }
            }
        }
        results.push_back(sum);
    }
    cout << "Part 2 using brute force: " << *min_element (results.begin(), results.end()) << endl;
}

int main(){
    vector<int> data;

     // Data prep - Read the sequence from input1.in and the boards from input2.in
    string fileName = "input.in";

    ifstream inputFile(fileName);
    
    int input;
    while(inputFile >> input){
        data.push_back(input);
    }

    part1_median(data);
    part2_brute(data);

}