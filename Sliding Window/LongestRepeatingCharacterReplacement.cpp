class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> charCount(26, 0); // Counts of characters in the current window
        int start = 0;                // Start of the current window
        int end = 0;                  // End of the current window
        int maxCharCount = 0;         // Maximum count of a single character in the current window
        int maxLength = 0;            // Maximum length of the substring with at most k replacements

        while (end < s.length())
        {
            // Update count of the current character
            charCount[s[end] - 'A']++;

            // Update maximum count of a single character
            maxCharCount = max(maxCharCount, charCount[s[end] - 'A']);

            // If the number of characters to replace exceeds k, shrink the window
            if (end - start + 1 - maxCharCount > k)
            {
                // Remove the character at the start of the window
                charCount[s[start] - 'A']--;
                start++;
            }

            // Update the maximum length of the substring
            maxLength = max(maxLength, end - start + 1);
            end++;
        }

        return maxLength;
    }
};
