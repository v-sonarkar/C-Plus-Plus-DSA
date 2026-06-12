// Find the minimum element in a rotated sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>



using namespace std;

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If search space is already sorted
        // then arr[low] will be the minimum
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        // Left part is sorted
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right part is sorted
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int result = findMin(arr);

    cout << "The minimum element in the rotated sorted array is: " << result << endl;

    return 0;
}
