// Search Insert Position Implementation
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Returns the index where the target should be inserted to maintain sorted order

#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& arr, int x) 
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        // maybe an answer
        if(arr[mid] >= x) {
            ans = mid;
            // look for more small index on left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look for right
        }
    }
    
    return ans;
}

int main() {
    vector<int> arr = {1, 3, 5, 6};
    int target = 5;

    int result = searchInsert(arr, target);

    cout << "Target " << target << " should be inserted at index: " << result << endl;

    return 0;
}