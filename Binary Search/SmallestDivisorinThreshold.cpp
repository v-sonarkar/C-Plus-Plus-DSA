// Returns the smallest divisor such that the sum of ceiling divisions is less than or equal to the threshold
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Brute Force 

int smallestDivisorBruteForce(vector<int>& arr, int threshold) {
    int n = arr.size();
    int maxEl = *max_element(arr.begin(), arr.end());
    
    for (int divisor = 1; divisor <= maxEl; divisor++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (arr[i] + divisor - 1) / divisor; // Ceiling division
        }
        if (sum <= threshold) {
            return divisor; // Found the smallest valid divisor
        }
    }
    
    return -1; // No valid divisor found (should not happen if threshold is valid)
}

// Binary Search Approach
int smallestDivisorBinarySearch(vector<int>& arr, int threshold) {
    int n = arr.size();
    int maxEl = *max_element(arr.begin(), arr.end());
    
    int low = 1;
    int high = maxEl;
    int ans = INT_MAX;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += (arr[i] + mid - 1) / mid; // Ceiling division
        }
        
        if (sum <= threshold) {
            ans = mid;         // Found a valid divisor, record it
            high = mid - 1;    // Look for a smaller, more optimal divisor on the left
        } 
        else {
            low = mid + 1;     // Divisor is too small, move to the right side
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    
    cout << "Smallest Divisor (Brute Force): " << smallestDivisorBruteForce(arr, threshold) << endl; // Expected output: 5
    cout << "Smallest Divisor (Binary Search): " << smallestDivisorBinarySearch(arr, threshold) << endl; // Expected output: 5
    
    return 0;
}