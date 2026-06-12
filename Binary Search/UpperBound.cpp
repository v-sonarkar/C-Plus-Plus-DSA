// Upper Bound Implementation
// Time Complexity: O(log n)
// Space Complexity: O(1)
// arr[result] is the first element that is greater than target
// smallest index of element which is greater than x


#include <vector>
#include <iostream>
using namespace std;

int upperBound(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // maybe an answer
        if (arr[mid] > x) {
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

    int result = upperBound(arr, n, x);

    if (result != n) {
        cout << "Upper bound of " << x << " is at index: " << result << endl;
    } else {
        cout << "No element greater than " << x << " found in the array." << endl;
    }

    return 0;
}


