// First and Last Element in a Sorted Array
#include <iostream>
#include <vector>
std::pair<int, int> findFirstAndLast(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int first = -1, last = -1;

    // Find the first occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            first = mid; // Update first occurrence
            right = mid - 1; // Continue searching in the left half
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
            last = mid; // Update last occurrence
            left = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return {first, last};
}

int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9, 10};
    int target = 5;

    auto result = findFirstAndLast(sortedArray, target);

    if (result.first != -1) {
        std::cout << "Element " << target << " found at indices: " << result.first << " and " << result.second << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}