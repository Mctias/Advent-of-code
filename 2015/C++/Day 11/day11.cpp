#include<iostream>

using namespace std;

// Find the next letter, z becomes a, skip i, l and o
char next_letter(char c){
    if(c == 'z'){
        c = 'a';
    }
    else if(c == 'h' || c == 'k' || c == 'n'){
        c+=2;
    }
    else{
        c+=1;
    }
    
    return c;
}

void next_password(string& password){
    int i = password.length() - 1;

    password[i] = next_letter(password[i]);
    
    // If the current letter is a we move back one and get the new letter
    while(password[i] == 'a' && i >= 0){
        i--;
        password[i] = next_letter(password[i]);
    }

}

bool isGood(string password){

    // For part b we can't have the first good password :)
    if(password == "vzbxxyzz")
        return false;

    // Pairs

    int pairCount = 0;
    char comp = '%';

    for(int i = 0; i < password.length() - 1; i++){
        
        if(password[i] == password[i+1] && password[i] != comp){
            pairCount++;
            comp = password[i];
        }
    }
    
    bool straight = false;

    // Straight increasing
    for(int i = 2; i < password.length(); i++){
        if((char)(password[i-2] + 1) == password[i-1] && (char)(password[i-1] + 1) == password[i]){
            straight = true;
            break;

        }
    }

    if(pairCount >= 2 && straight){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    string password = "vzbxkghb";
    
    // While the password is bad calculate a new one
    while(!isGood(password)) next_password(password);

    cout << password;
}