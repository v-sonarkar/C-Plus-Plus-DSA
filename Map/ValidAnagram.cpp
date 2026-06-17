// Valid Anagram
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//using Two Maps
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> charCountS;
    unordered_map<char, int> charCountT;

    for (char c : s) {
        charCountS[c]++; // Count characters in string s & 
    }   


    for (char c : t) {
        charCountT[c]++;
    }

  for (auto x:charCountS){
    char ch1 = x.first;
    int freq1 = x.second;

    if (charCountT.find(ch1) != charCountT.end() ) {
            int freq2 = charCountT[ch1];
            if (freq1 != freq2) return false;
    }
    else return false;
  }
  return true;
}


//using One Map
bool isAnagramOptimized(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> charCount;

    for(int i=0;i<s.length();i++){
        charCount[s[i]]++; // Count characters in string s & 
        
    }
    for(int i=0;i<t.length();i++){
        char ch=t[i];
        if (charCount.find(ch) != charCount.end() ) {
            charCount[ch]--;
            if (charCount[ch] == 0) charCount.erase(ch); // Remove the character from the map if its count becomes zero
        }
        else return false; // Character in t not found in s

    }
    if (charCount.size() != 0) {
        return false; // If there are still characters left in the map, then s and t are not anagrams

    }

    return true;
        
}
int main() {
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t)) {
        cout << s << " and " << t << " are anagrams." << endl;
    } else {
        cout << s << " and " << t << " are not anagrams." << endl;
    }

    if (isAnagramOptimized(s, t)) {
        cout << s << " and " << t << " are anagrams (optimized check)." << endl;
    } else {
        cout << s << " and " << t << " are not anagrams (optimized check)." << endl;
    }

    return 0;
}