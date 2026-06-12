// Recursive Binary Search

#include <iostream>
#include <vector>

int recursiveBinarySearch(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Target not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Target found
    }

    if (arr[mid] < target) {
        return recursiveBinarySearch(arr, target, mid + 1, right);
    } else {
        return recursiveBinarySearch(arr, target, left, mid - 1);
    }
}

int binarySearch(const std::vector<int>& arr, int target) {
    return recursiveBinarySearch(arr, target, 0, arr.size() - 1);
}

int main() {
    std::vector<int> sortedArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    int result = binarySearch(sortedArray, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index: " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}

