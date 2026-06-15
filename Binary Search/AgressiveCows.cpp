// Agressive Cows
// Given n stalls and c cows, find the largest minimum distance between the cows when they are placed in the stalls
// Answer lies betwween 1 and (max-min) where max and min are the maximum and minimum stall positions respectively
// Time Complexity: O(n log m) where n is the number of stalls and m is the range of possible distances (from 1 to max-min)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//Brute Force Approach
int aggressiveCowsBruteForce(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int maxDistance = 0;
    
    for (int i = 0; i < stalls.size(); i++) {
        for (int j = i + 1; j < stalls.size(); j++) {
            int distance = stalls[j] - stalls[i];
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }
    
    return maxDistance;
}


// Binary Search Approach


bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int cntCows = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    
    // min of all consecutive distance difference
    int low = 1, high = stalls[n - 1] - stalls[0];
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    
    cout << "Largest minimum distance (Brute Force): " << aggressiveCowsBruteForce(stalls, cows) << endl; // Expected output: 3
    cout << "Largest minimum distance (Binary Search): " << aggressiveCows(stalls, cows) << endl; // Expected output: 3
    
    return 0;
}