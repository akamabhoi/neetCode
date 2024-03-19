class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();            // Length of the input string
        int maxLength = 0;           // Maximum length of substring without repeating characters
        unordered_set<char> charSet; // Set to store characters in the current substring
        int left = 0;                // Left pointer of the sliding window

        for (int right = 0; right < n; right++)
        {
            // If the current character is already in the set, remove characters from the set
            while (charSet.find(s[right]) != charSet.end())
            {
                charSet.erase(s[left]); // Remove the character at 'left' from the set
                ++left;                 // Move 'left' forward
            }

            // Add the current character to the set
            charSet.insert(s[right]);

            // Update maxLength
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength; // Return the maximum length of substring without repeating characters
    }
};
