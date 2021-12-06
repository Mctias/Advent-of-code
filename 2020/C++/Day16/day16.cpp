#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>


using namespace std;

void extractIntegersFromString(string input, int index, vector<vector<int>> &ranges){
    int found;
    stringstream ss;

    ss << input;
    string tmp;

    while(!ss.eof()){
        ss >> tmp;

        if(stringstream(tmp) >> found)
            ranges[index].push_back(found);

        tmp = " ";
    }

}

void extractIntegersFromString2(string input, int index,vector<vector<int>> &tickets){
    int found;
    stringstream ss(input);

    for(int i; ss >> i;){
        tickets[index].push_back(i);

        if(ss.peek() == ',')
            ss.ignore();
    }

    

}


int main(){

    int size = 20;

    vector<vector<int>> ranges(size);

    string fileName1 = "ranges.in";

    ifstream inputFile1(fileName1);
    string input1;
    int counter = 0;

    while(getline(inputFile1, input1)){
        extractIntegersFromString(input1, counter, ranges);
        counter++;

    }

    string fileName2 = "tickets.in";

    ifstream inputFile2(fileName2);
    string input2;

    vector<vector<int>> tickets(242);
    counter = 0;

    while(getline(inputFile2, input2)){
        extractIntegersFromString2(input2, counter, tickets);
        counter++;

    }

    bool isBad;
    int result = 0;
    int indexCounter = 0;

   // cout << ranges[0][0] << " " << ranges[0][1] << " "; 

    for(auto i : tickets){
        for(auto ii : i){
            isBad = false;

            for(auto iii : ranges){
                if((iii[0] <= ii && ii <= iii[1] )|| (iii[2] <= ii && ii <= iii[3])){
                    isBad = false;
                    break;
                }
                    
                else{
                    
                    isBad = true;
                }
                // cout << tickets[i] << " " << ii[0] << " " << ii[1] << " " << ii[2] << " " << ii[3] << endl;
            }

            if(isBad){
                result += ii;
                tickets.erase(tickets.begin() + indexCounter);
            }
         }
         indexCounter++;
    }
    tickets.erase(tickets.begin() + 0);

    
    vector<pair<int,int>> matches;
    int goodCounter = 0;

    



    

    for(int i = 1; i < 2; i++){
        for(int k = 0; k < ranges.size(); k++){
            cout << "Checking field " << k + 1 << ": ";
            goodCounter = 0;
            for(int j = 0; j < tickets.size(); j++){
                if((ranges[k][0] <= tickets[j][i] &&  tickets[j][i] <= ranges[k][1])
                    || (ranges[k][2] <= tickets[j][i] &&  tickets[j][i] <= ranges[k][3])){
                        goodCounter++;
                    }
                else{
                    cout << endl << tickets[j][i] << " is bad for field " << k + 1 << endl;
                    goodCounter = 0;
                    break;
                }
                //cout << goodCounter << endl;

                if(goodCounter == tickets.size())
                    cout << endl << "Column " << i + 1 << " is good for field " << k + 1 << endl;

                    
            }

        }
    }

        
}
