#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{

    int in;
    string filename = "input.in";

    ifstream input_file(filename);

    vector<int> data;

    while (input_file >> in)
    {
        data.push_back(in);
    }

    long long arr[9] = {0};

    for (auto j : data)
    {
        arr[j]++;
    }

    for (int i = 0; i < 256; i++)
    {
        long long fishToSpawn = arr[0];
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[3];
        arr[3] = arr[4];
        arr[4] = arr[5];
        arr[5] = arr[6];
        arr[6] = arr[7] + fishToSpawn;
        arr[7] = arr[8];
        arr[8] = fishToSpawn;
    }

    long long sum = 0;

    for (int i = 0; i < 9; i++)
    {
        sum += arr[i];
    }
    cout << sum;
}