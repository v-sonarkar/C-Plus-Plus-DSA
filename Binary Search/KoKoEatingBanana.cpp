// Returns the min integer k such that Koku can eat all bananas within h hours
// K will lie from 1 to maxEl(arr) where maxEl(arr) is the maximum element in the array
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Helper function to calculate total hours needed with an eating speed 'k'
long long calculateTotalHours(const vector<int>& arr, int k) {
    long long totalHrs = 0;
    for (int i = 0; i < arr.size(); i++) {
        // Ceiling division: (arr[i] + k - 1) / k avoids floating-point precision issues
        totalHrs += (arr[i] + k - 1) / k;
    }
    return totalHrs;
}

// Binary search function as structured on the digital board
int minEatingSpeed(vector<int>& arr, int h) {
    // Find the maximum element in the array to set the upper boundary (high = maxEl(arr))
    int maxEl = 0;
    for (int i = 0; i < arr.size(); i++) {
        maxEl = max(maxEl, arr[i]);
    }
    
    // Initializations from Image 1000076681.jpg
    int low = 1;
    int high = maxEl;
    int ans = INT_MAX;
    
    // Binary search loop
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        
        long long totalHrs = calculateTotalHours(arr, mid);
        
        // Conditional logic from Image 1000076682.jpg
        if (totalHrs <= h) {
            ans = mid;         // Found a valid speed, record it
            high = mid - 1;    // Look for a smaller, more optimal speed on the left
        } 
        else {
            low = mid + 1;     // Speed is too slow, move to the right side
        }
    }
    
    return ans;
}

int main() {
    // Test Case 1
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Test Case 1:" << endl;
    cout << "Piles: [3, 6, 7, 11], Hours allowed: " << h1 << endl;
    cout << "Minimum eating speed (k): " << minEatingSpeed(piles1, h1) << endl; // Expected output: 4
    
    cout << "---------------------------------------" << endl;

    // Test Case 2
    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Test Case 2:" << endl;
    cout << "Piles: [30, 11, 23, 4, 20], Hours allowed: " << h2 << endl;
    cout << "Minimum eating speed (k): " << minEatingSpeed(piles2, h2) << endl; // Expected output: 30

    return 0;
}