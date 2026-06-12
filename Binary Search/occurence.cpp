// Occurrence of an Element in a Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int countOccurrences(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int first = -1, last = -1;

    // Find the first occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            first = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Reset left and right for finding the last occurrence
    left = 0;
    right = arr.size() - 1;

    // Find the last occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            last = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (first == -1) {
        return 0; // Element not found
    }

    return last - first + 1; // Return the count of occurrences
}

int main() {
    vector<int> sortedArray = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    int target = 5;

    int count = countOccurrences(sortedArray, target);

    cout << "Element " << target << " occurs " << count << " times in the array." << endl;

    return 0;
}
