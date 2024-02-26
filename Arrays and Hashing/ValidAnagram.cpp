class Solution {
public:
// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    // Create an unordered map to store the frequency of each character in the first string
    unordered_map<int, int> mp;

    // Count the frequency of each character in the first string
    for(auto letter: s){
        mp[letter]++;
    }

    // Decrement the frequency of each character in the second string
    for(auto letter: t){
        mp[letter]--;
    }

    // Check if all character frequencies are zero, indicating an anagram
    for(auto x: mp){
        if(x.second != 0){
            // If any character frequency is non-zero, strings are not anagrams
            return false;
        }
    }

    // All character frequencies are zero, strings are anagrams
    return true;
}

};