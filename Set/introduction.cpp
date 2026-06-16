// Introduction to Sets in C++
// A set is a collection of unique elements. In C++, the standard library provides the `std::unordered_set` container, which is implemented as a hash table. This means that the elements in a set are stored without any particular order, and the operations like insertion, deletion, and searching have average constant time complexity.
// it is stored in hash table and it is unordered and it is unique means no duplicate values are allowed in set
// The main operations of a set include:
// insert() - O(1) on average, O(n) in worst case due to hash collisions
// find() - O(1) on average, O(n) in worst case due to hash collisions
// erase() - O(1) on average, O(n) in worst case due to hash collisions
// size() - O(1)

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // Create a set of integers
    unordered_set<int> mySet;

    // Insert elements into the set
    mySet.insert(5);
    mySet.insert(3);
    mySet.insert(8);
    mySet.insert(5); // Duplicate element, will not be added

    // Display the elements in the set
    cout << "Elements in the set: ";
    for (int num : mySet) {
        cout << num << " ";
    }
    cout << endl;

    // Check if an element exists in the set
    //.find() returns an iterator to the element if found, or mySet.end() if not found
    int elementToFind = 3;
    if (mySet.find(elementToFind) != mySet.end()) { ///target element is found in the set
        cout << elementToFind << " found in the set." << endl;
    } else {
        cout << elementToFind << " not found in the set." << endl;
    }

    // Erase an element from the set
    mySet.erase(3);

    // Display the elements in the set after erasing
    cout << "Elements in the set after erasing 3: ";
    for (int num : mySet) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

