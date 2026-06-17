// Ordered Map
// It allows us to store key-value pairs in a sorted order based on the keys. The elements are automatically sorted in ascending order of the keys when inserted into the map. The map does not allow duplicate keys, and it provides efficient operations for insertion, deletion, and searching.
// Time Complexity: O(log n) for insertion, deletion, and searching.
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> orderedMap;
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[4] = "Four";
    orderedMap[2] = "Two";

    for ( auto pair : orderedMap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}

