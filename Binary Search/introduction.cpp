// Binary Search Introduction
// Time Complexity: O(log n)
// Space Complexity: O(1)
// if the search space is not arrray and it is between 0 and INI_MAX,then there might be case where low and high is at INT_MAX and low+high will cause overflow,so we can use mid=low+(high-low)/2 to avoid overflow

#include <iostream>
#include <vector>

// Function to perform binary search on a sorted vector
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To avoid overflow

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found, return index
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Target not found in the array
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

