// Floor and Ceiling Implementation
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Floor of x is the largest element in the array that is less than or equal to x
// Ceiling of x is the smallest element in the array that is greater than or equal to x

#include <vector>
#include <iostream>
using namespace std;

int floor(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            ans = mid;
            low = mid + 1;   // look for larger index on right
        } else {
            high = mid - 1;    // look on left
        }
    }

    return ans;
}

int ceil(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;   // look for smaller index on left
        } else {
            low = mid + 1;    // look on right
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 6};
    int n = arr.size();
    int x = 4;

    int floorResult = floor(arr, n, x);
    int ceilResult = ceil(arr, n, x);

    if (floorResult != -1) {
        cout << "Floor of " << x << " is at index: " << floorResult << endl;
    } else {
        cout << "No element less than or equal to " << x << " found in the array." << endl;
    }

    if (ceilResult != n) {
        cout << "Ceiling of " << x << " is at index: " << ceilResult << endl;
    } else {
        cout << "No element greater than or equal to " << x << " found in the array." << endl;
    }

    return 0;
}