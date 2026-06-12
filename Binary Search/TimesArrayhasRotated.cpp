// Find the number of times a sorted array has been rotated
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>
#include <climits>
using namespace std;
int findMinIndex(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        // If the search space is already sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right half is sorted
        else {
            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}



int findMinIndex(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If the array segment is already sorted
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                ans = min(ans, arr[low]);
                index = low;
            }
            break;
        }

        // Left part is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans = min(ans, arr[low]);
                index = low;
            }
            low = mid + 1;
        }
        // Right part is sorted
        else {
            if (arr[mid] < ans) {
                ans = min(ans, arr[mid]);
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int minIndex = findMinIndex(arr);

    if (minIndex != -1) {
        cout << "The array has been rotated " << minIndex << " times." << endl;
    } else {
        cout << "The array is not rotated." << endl;
    }

    return 0;
}