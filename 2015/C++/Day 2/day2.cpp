#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

// Data prep

vector<int> extractInts(string s){
    stringstream ss;
    vector<int> result;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'x'){
            s[i] = ' ';
        }
    }


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

int findExtra(int l, int w, int h){
    if(l >= w && l >=h)
        return w*h;
    else if(w >= l && w >= h)
        return l*h;
    else if(h >= l && h >= w) 
        return l*w;

    return 0;
}

// Part 2
int findRibbon(int l, int w, int h){
    if(l >= w && l >=h)
        return 2*(w+h);
    else if(w >= l && w >= h)
        return 2*(l+h);
    else if(h >= l && h >= w) 
        return 2*(l+w);

    return 0;
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

    vector<vector<int>> intData;

    for(auto i : data){
        intData.push_back(extractInts(i));
    }

    // Part 1 

    int paper = 0;
    for(int i = 0; i < intData.size(); i++){
        int l = intData[i][0];
        int w = intData[i][1];
        int h = intData[i][2];

        int surface = 2*l*w + 2*w*h + 2*h*l;
        paper += surface;

        int extra = findExtra(l,w,h);

        paper += extra;
    }

    cout << paper << endl;


    // Part 2

    int ribbon = 0;

    for(int i = 0; i < intData.size(); i++){
        int l = intData[i][0];
        int w = intData[i][1];
        int h = intData[i][2];

        int toWrap = findRibbon(l,w,h);
        int bow = l*w*h;

        ribbon += toWrap + bow;
    }

    cout << ribbon;

    return 0;
}