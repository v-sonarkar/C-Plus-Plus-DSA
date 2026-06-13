// Peak Element in an Array
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>

int findPeakElement(const std::vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is a peak element
        if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
            return mid;
        }
        // If the element to the left of mid is greater, then there must be a peak element on the left side
        else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;
        }
        // Otherwise, there must be a peak element on the right side
        else {
            low = mid + 1;
        }
    }

    return -1; // No peak element found
}

int main() {
    std::vector<int> arr = {1, 3, 20, 4, 1, 0};
    int peakIndex = findPeakElement(arr);
    if (peakIndex != -1) {
        std::cout << "Peak element found at index " << peakIndex << " with value " << arr[peakIndex] << std::endl;
    } else {
        std::cout << "No peak element found." << std::endl;
    }
    return 0;
}   