// Find the number of times a sorted array has been rotated
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>
using namespace std;

int findRotationCount(vector<int> arr, int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid element is greater than the last element, the rotation point is in the right half
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            // Otherwise, the rotation point is in the left half (including mid)
            high = mid;
        }
    }

    return low; // The number of rotations
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();

    int result = findRotationCount(arr, n);

    cout << "The array has been rotated " << result << " times." << endl;

    return 0;
}