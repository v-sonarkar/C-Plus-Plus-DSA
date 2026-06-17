// Ordered Set
// It allows us to store unique elements in a sorted order. The elements are automatically sorted in ascending order when inserted into the set. The set does not allow duplicate elements, and it provides efficient operations for insertion, deletion, and searching.

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
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}