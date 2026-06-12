// Rotated Sorted Array Implementation
//All elements are distinct in the array
//Indentify the sorted half of the array and determine if the target is in that half or the other half, then adjust the search space accordingly.
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Find the index of a target element in a rotated sorted array

#include <vector>
#include <iostream>
using namespace std;

int search(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        // Check if left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if target is in the left half
            if (arr[low] <= x && x < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // Right half is sorted
            // Check if target is in the right half
            if (arr[mid] < x && x <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1; // Element not found
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();
    int x = 0;

    int result = search(arr, n, x);

    if (result != -1) {
        cout << "Element " << x << " found at index: " << result << endl;
    } else {
        cout << "Element " << x << " not found in the array." << endl;
    }

    return 0;
}