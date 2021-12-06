#include<iostream>
#include<vector>


using namespace std;

// This solution uses two for loops to calculate the answer
// Not the most efficient and perhaps could have been done more efficient by using regex instead

int main(){

    vector<int> data = {1, 1, 1, 3, 2, 2, 2, 1, 1, 3};

    int counter = 1;

    // Repeat the process 50 times 
    for(int x = 1; x <= 50; x++){

        vector<int> tmp;

        for(int i = 0; i < data.size(); i++){

            // Is the next item the same as the current inc the counter and continue
            // Also check that this isn't the last item in our vector or else we'll get wonky results :)
            if(data[i] == data[i+1] && i != data.size() - 1){
                counter++;
                continue;
            }
            
            // Else save our counter and the current item and reset counter
            else{
                tmp.push_back(counter);
                tmp.push_back(data[i]);
                counter = 1;
                continue;
            }
        }

        // Clear the data vector and set it to our tmp
        // Then the next iteration will use the new data
        data.clear();
        data = tmp;

        // Write down the answer for part 1 :)
        if(x == 40){
            cout << "The result of part 1 is: " << data.size() << endl;
        }
    }
    
    cout << "The result of part 2 is: " << data.size();
}