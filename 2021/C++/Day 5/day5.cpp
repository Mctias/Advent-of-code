#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int grid[989][989] = {0};

vector<int> splitString(string s)
{
    vector<int> result;
    string word = "";

    for (auto c : s)
    {
        if (c == ' ')
        {
            int x = stoi(word);
            result.push_back(x);
            word = "";
        }
        else
        {
            word += c;
        }
    }

    return result;
}

int main()
{

    string in;
    string filename = "input.in";
    ifstream input_file(filename);

    vector<vector<int>> data;

    while (getline(input_file, in))
    {
        data.push_back(splitString(in));
    }

    for (int i = 0; i < data.size(); i++)
    {
        int x1 = data[i][0];
        int x2 = data[i][2];

        int y1 = data[i][1];
        int y2 = data[i][3];

        if (x1 == x2)
        {

            if ((y1 - y2) < 0)
            {
                for (int j = y1; j <= y2; j++)
                {
                    grid[j][x1]++;
                }
            }
            else
            {
                for (int j = y2; j <= y1; j++)
                {
                    grid[j][x1]++;
                }
            }
        }
        else if (y1 == y2)
        {
            if ((x1 - x2) < 0)
            {
                for (int j = x1; j <= x2; j++)
                {
                    grid[y1][j]++;
                }
            }
            else
            {
                for (int j = x2; j <= x1; j++)
                {
                    grid[y1][j]++;
                }
            }
        }
        else
        {
            if ((x1 - x2) < 0 && (y1 - y2) < 0)
            {
                int x = x1;
                int y = y1;

                while (x <= x2 && y <= y2)
                {
                    grid[y][x]++;
                    x++;
                    y++;
                }
            }
            else if ((x1 - x2) > 0 && (y1 - y2) < 0)
            {
                int x = x1;
                int y = y1;

                while (x >= x2 && y <= y2)
                {
                    grid[y][x]++;
                    x--;
                    y++;
                }
            }
            else if ((x1 - x2) < 0 && (y1 - y2) > 0)
            {
                int x = x1;
                int y = y1;

                while (x <= x2 && y >= y2)
                {
                    grid[y][x]++;
                    x++;
                    y--;
                }
            }
            else if ((x1 - x2) > 0 && (y1 - y2) > 0)
            {
                int x = x1;
                int y = y1;

                while (x >= x2 && y >= y2)
                {
                    grid[y][x]++;
                    x--;
                    y--;
                }
            }
        }
    }

    int sum = 0;

    for (int i = 0; i <= 989; i++)
    {
        for (int j = 0; j <= 989; j++)
        {
            if (grid[i][j] > 1)
            {
                sum++;
                cout << grid[i][j] << endl;
            }
        }
    }

    cout << sum;
}