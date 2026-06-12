// Lower Bound Implementation
// Time Complexity: O(log n)
// Space Complexity: O(1)
// arr[result] is the first element that is greater than or equal to target
// smallest index of element which is greater than or equal to x



#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // maybe an answer
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

    int result = lowerBound(arr, n, x);

    if (result != n) {
        cout << "Lower bound of " << x << " is at index: " << result << endl;
    } else {
        cout << "No element greater than or equal to " << x << " found in the array." << endl;
    }

    return 0;
}   