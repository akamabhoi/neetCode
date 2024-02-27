class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Vector to store the grouped anagrams
        vector<vector<string>> ans;

        // Map to efficiently store anagrams, where the key is the sorted version of the word
        unordered_map<string, vector<string>> mp;

        // Iterate through the input vector of words
        for(auto originalWord : strs) {
            // Create a copy of the word and sort its characters to get the key for the map
            string sortedWord = originalWord;
            sort(sortedWord.begin(), sortedWord.end());

            // Add the original word to its corresponding group in the map
            mp[sortedWord].push_back(originalWord);
        }

        // Iterate through the anagram map and add groups to the result vector
        for(auto anagramGroup : mp) {
            ans.push_back(anagramGroup.second);
        }

        // Return the final grouped anagrams
        return ans;
    }
};