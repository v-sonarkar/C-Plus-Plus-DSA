// Maximum Number of String Pairs
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
// Ist approach
int maxPairs(vector<string>& words) {
    unordered_set<string> wordSet;
    int pairs = 0;
for (int i = 0; i < words.size(); i++) {
        string reversedWord = string(words[i].rbegin(), words[i].rend());
        if (wordSet.find(reversedWord) != wordSet.end()) {
            pairs++;
            wordSet.erase(reversedWord); // Remove the matched pair
        } else {
            wordSet.insert(words[i]); // Add the current word to the set
        }
    }
    return pairs;
}

// IInd approach
int maxPairsAlternative(vector<string>& words) {
    int pairs = 0;
    for (int i = 0; i < words.size(); i++) {
        for (int j = i + 1; j < words.size(); j++) {
            if (words[i] == string(words[j].rbegin(), words[j].rend())) {
                pairs++;
            }
        }
    }
    return pairs;
}

int main() {
    vector<string> words = {"abc", "cba", "ghi", "jkl"};
    cout << "Maximum number of string pairs: " << maxPairs(words) << endl;
    cout << "Alternative approach: " << maxPairsAlternative(words) << endl;
    return 0;
}
