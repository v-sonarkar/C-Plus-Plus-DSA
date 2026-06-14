// Returns the maximum divisor such that the sum of ceiling divisions is less than or equal to the threshold
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Binary Search Approach
int maximumDivisorBinarySearch(vector<int>& arr, int threshold) {
    int n = arr.size();
    int maxEl = *max_element(arr.begin(), arr.end());
    
    int low = 1;
    int high = maxEl;
    int ans = INT_MIN;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += (arr[i] + mid - 1) / mid; // Ceiling division
        }
        
        if (sum <= threshold) {
            ans = mid;         // Found a valid divisor, record it
            low = mid + 1;     // Look for a larger divisor on the right
        } 
        else {
            high = mid - 1;    // Divisor is too large, move to the left side
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    
    cout << "Maximum Divisor (Binary Search): " << maximumDivisorBinarySearch(arr, threshold) << endl; // Expected output: 9
    
    return 0;
}