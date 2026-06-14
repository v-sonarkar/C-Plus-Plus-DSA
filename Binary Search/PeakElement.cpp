// Peak Element in an Array
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>

#include <vector>

using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    
    // Edge cases
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;
    
    // Binary search boundaries
    int low = 1, high = n - 2;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        // If mid is a peak element
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        
        // If we are on an increasing slope, the peak is to the right
        else if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        }
        // If we are on a decreasing slope (or a local valley), the peak is to the left
        else {
            high = mid - 1;
        }
    }
    
    return -1;
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