// Painter Partition Problem // Split Array Largest Sum
// Given an array of non-negative integers and an integer m, you need to split this array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;

//Brute Force Approach
// Helper function to calculate the number of subarrays needed with max sum 'mid'
int countSubarrays(vector<int>& arr, int mid) {
    int count = 1; // Start with one subarray
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (currentSum + arr[i] > mid) {
            count++; // Need to start a new subarray
            currentSum = arr[i]; // Start the new subarray with the current element
        } else {
            currentSum += arr[i]; // Add to the current subarray
        }
    }
    return count;
}

// Main function rewritten exactly like the blackboard image
int splitArray(vector<int>& arr, int m) {
    int low = *max_element(arr.begin(), arr.end()); // The largest single element is the minimum possible max sum
    int high = accumulate(arr.begin(), arr.end(), 0); // The sum of all elements is the maximum possible max sum

    for (int mid = low; mid <= high; mid++) {
        int requiredSubarrays = countSubarrays(arr, mid);
        if (requiredSubarrays <= m) {
            return mid; // Found a valid max sum, return it
        }
    }
    return -1; // No valid split found (should not happen if m is valid)
}

// Binary Search Approach
int splitArrayBinarySearch(vector<int>& arr, int m) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = high; // Initialize to the upper bound

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        int requiredSubarrays = countSubarrays(arr, mid);

        if (requiredSubarrays <= m) {
            ans = mid;         // Found a valid max sum, record it
            high = mid - 1;    // Look for a smaller max sum on the left
        } 
        else {
            low = mid + 1;     // Max sum is too small, move to the right side
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {7, 2, 5, 10, 8};
    int m = 2;

    cout << "Minimum largest sum among " << m << " subarrays (Brute Force): " << splitArray(arr, m) << endl; // Expected output: 18
    cout << "Minimum largest sum among " << m << " subarrays (Binary Search): " << splitArrayBinarySearch(arr, m) << endl; // Expected output: 18

    return 0;
}
