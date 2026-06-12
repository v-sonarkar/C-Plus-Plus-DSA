// Find the minimum element in a rotated sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>
using namespace std;

int findMin(vector<int> arr, int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Check if mid element is greater than the last element
        if (arr[mid] > arr[high]) {
            low = mid + 1; // Minimum is in the right half
        } else {
            high = mid; // Minimum is in the left half including mid
        }
    }

    return arr[low]; // The minimum element
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();

    int result = findMin(arr, n);

    cout << "The minimum element in the rotated sorted array is: " << result << endl;

    return 0;
}
