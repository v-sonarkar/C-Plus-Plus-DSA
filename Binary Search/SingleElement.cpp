// Single Element in an Array
// Time Complexity: O(log n)
// Space Complexity: O(1)
// if i am standing at one index ,either left ot right have this element
// if am standing on even index and there is similar element in right side then i am standing on left half
// if am standing on odd index and there is similar element in right side then i am standing on right half
// (even,odd)
// (odd,even)

#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& arr) 
{
    int n = arr.size();
    
    // Edge cases
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
    
    // Binary search boundaries
    int low = 1, high = n - 2;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        // If mid is the single element
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }
        
        // Check if we are in the left half
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) 
            || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            // Shrink the left half, single element is on the right
            low = mid + 1;
        } 
        // We are in the right half
        else {
            // Shrink the right half, single element is on the left
            high = mid - 1;
        }
    }
    
    return -1;
}

int main(){





    
}
