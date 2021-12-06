#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// This hashing funciton isn't the best but it works for now
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;  
    }
};

unordered_map<pair<int,int> , int, pair_hash> cityConnections;

// Adds the edge and weigth to the hash table
void addEdge(int c1, int c2, int wgt){
    pair<int,int> connection = make_pair(c1,c2);

    cityConnections[connection] = wgt;
}

// Build the hash table which will include every connection with its corresponding weight
void buildHashTable(){

    // Could do this better :)
    // These will be all of our connections
    // Since it's an undirected graph we have to insert in both directions

    addEdge(0, 1, 129);
    addEdge(1, 0, 129);
    addEdge(0, 2, 58);
    addEdge(2, 0, 58);
    addEdge(0, 3, 13);
    addEdge(3, 0, 13);
    addEdge(0, 4, 24);
    addEdge(4, 0, 24);
    addEdge(0, 5, 60);
    addEdge(5, 0, 60);
    addEdge(0, 6, 71);
    addEdge(6, 0, 71);
    addEdge(0, 7, 67);
    addEdge(7, 0, 67);

    addEdge(1, 2, 142);
    addEdge(2, 1, 142);
    addEdge(1, 3, 15);
    addEdge(3, 1, 15);
    addEdge(1, 4, 135);
    addEdge(4, 1, 135);
    addEdge(1, 5, 75);
    addEdge(5, 1, 75);
    addEdge(1, 6, 82);
    addEdge(6, 1, 82);
    addEdge(1, 7, 54);
    addEdge(7, 1, 54);

    addEdge(2, 3, 118);
    addEdge(3, 2, 118);
    addEdge(2, 4, 122);
    addEdge(4, 2, 122);
    addEdge(2, 5, 103);
    addEdge(5, 2, 103);
    addEdge(2, 6, 49);
    addEdge(6, 2, 49);
    addEdge(2, 7, 97);
    addEdge(7, 2, 97);

    addEdge(3, 4, 116);
    addEdge(4, 3, 116);
    addEdge(3, 5, 12);
    addEdge(5, 3, 12);
    addEdge(3, 6, 18);
    addEdge(6, 3, 18);
    addEdge(3, 7, 91);
    addEdge(7, 3, 91);

    addEdge(4, 5, 129);
    addEdge(5, 4, 129);
    addEdge(4, 6, 53);
    addEdge(6, 4, 53);
    addEdge(4, 7, 40);
    addEdge(7, 4, 40);

    addEdge(5, 6, 15);
    addEdge(6, 5, 15);
    addEdge(5, 7, 99);
    addEdge(7, 5, 99);

    addEdge(6, 7, 70);
    addEdge(7, 6, 70);
    
}
  
// We use the hash table to find the total distance/cost of the given path
int findDistance(vector<int> path){

    int distance = 0;

    for(int i = 0; i < path.size() - 1; i++){
        pair<int,int> connection = make_pair(path[i], path[i+1]);

        distance += cityConnections[connection];
    }

    return distance;
}

// Build the path vector
vector<int> buildPath(int a[], int n)
{
    vector<int> vec;
    for(int i = 0; i < n; i++){
        vec.push_back(a[i]);
    }

    return vec;
}
  
// Function to find the permutations
// Which is all the possible ways we can travel
// (There's a lot)
vector<vector<int>> findPermutations(int a[], int n)
{   
    vector<vector<int>> result;
  
    // Sort the given array
    sort(a, a + n);
  
    // Find all possible permutations
    do {
        result.push_back(buildPath(a, n));
    } while (next_permutation(a, a + n));

    return result;
}

int main(){

    buildHashTable();

    // All out cities, represented by numbers
    int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  
    int n = sizeof(a) / sizeof(a[0]);
    
    // All the possible paths santa can take
    vector<vector<int>> possiblePaths = findPermutations(a, n);

    vector<int> distances;

    // Find the distances of all our paths
    // Could make this faster by not checking paths we already checked
    for(auto i : possiblePaths){
        distances.push_back(findDistance(i));
    }

    // Find the min and max elements in our distances vector

    // Part 1 (min)
    int minDistance = *min_element(distances.begin(), distances.end());
    cout << "The shortest possible way: " << minDistance << endl;

    // Part 2 (max)
    int maxDistance = *max_element(distances.begin(), distances.end());
    cout << "The longest possible way: " << maxDistance;
}