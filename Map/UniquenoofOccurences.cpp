// Unique Number of Occurrences
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
   int n=arr.size();
    unordered_map<int,int> m; // Map to store frequency of each number
    for(int i=0;i<n;i++){
        m[arr[i]]++; // Count the occurrences of each number
    }
unordered_set<int> s; // Set to store unique frequencies
    for(auto x:m){
        int freq = x.second; // Get the frequency of the current number
        if(s.find(freq) != s.end()) { // Check if this frequency has already been seen
            return false; // If it has, return false
        }
         else {
            s.insert(freq); // Otherwise, add this frequency to the set
        }
    }
    return true; // If all frequencies are unique, return true
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    if (uniqueOccurrences(arr)) {
        cout << "All occurrences are unique." << endl;
    } else {
        cout << "There are duplicate occurrences." << endl;
    }
    return 0;
}