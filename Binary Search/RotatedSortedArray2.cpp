// Rotated Sorted Array Implementation  
// Double elements are present in the array
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        // If duplicates are present, we cannot determine which half is sorted
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
        }
        // Check if left half is sorted
        else if (arr[low] <= arr[mid]) {
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
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 4, 4};
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