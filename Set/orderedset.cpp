// Ordered Set
// It allows us to store unique elements in a sorted order. The elements are automatically sorted in ascending order when inserted into the set. The set does not allow duplicate elements, and it provides efficient operations for insertion, deletion, and searching.
// Time Complexity: O(log n) for insertion, deletion, and searching.
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(1);
    s.insert(9);

    cout << "Elements in the ordered set: ";
    for (int ele : s) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}

