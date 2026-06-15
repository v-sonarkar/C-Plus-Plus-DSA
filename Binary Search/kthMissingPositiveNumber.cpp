// Kth Missing Positive Number
// Given a sorted array of positive integers and an integer k, find the kth missing positive integer.
// Time Complexity: O(log n) where n is the size of the input array
// Space Complexity: O(1)
// The idea is to use binary search to find the position where the kth missing number would fit in the array.
// The number of missing numbers until index mid can be calculated as arr[mid] - (mid + 1) because if there were no missing numbers, arr[mid] would be equal to mid + 1.


#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach
int findKthPositive(vector<int>& arr, int k) {
    for(int i=0;i<arr.size();i++){
        if (arr[i]<k) {
            k++;
        } else {
            break;
        }
    }
    return k;
}
// Binary Search Approach

//missingcount = arr[mid] - (mid + 1) because if there were no missing numbers, arr[mid] would be equal to mid + 1.
//For example, if arr[mid] is 5 and mid is 2, then the missing count until index mid would be 5 - (2 + 1) = 2, which means there are 2 missing numbers before index mid.
//
//
int findKthPositiveBinarySearch(vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential integer overflow
        int missingCount = arr[mid] - (mid + 1); // Calculate missing numbers until index mid
        
        if (missingCount < k) {
            low = mid + 1; // Move to the right half
        } else {
            high = mid - 1; // Move to the left half
        }
    }
    
    return low + k; // The kth missing number will be low + k
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    
    cout << "Kth Missing Positive Number (Brute Force): " << findKthPositive(arr, k) << endl; // Expected output: 9
    cout << "Kth Missing Positive Number (Binary Search): " << findKthPositiveBinarySearch(arr, k) << endl; // Expected output: 9
    
    return 0;
}
