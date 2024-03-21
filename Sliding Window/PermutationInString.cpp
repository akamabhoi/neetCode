class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        // Initialize start and end indices to represent the window size of s1 in s2
        int start = 0, end = s1.size() - 1;

        // Initialize a vector to count characters in s1
        vector<int> charCount(26, 0);

        // Count characters in s1
        for (char ch : s1)
        {
            charCount[ch - 'a']++;
        }

        // Loop through the windows of s2
        while (end < s2.size())
        {
            // Initialize a vector to count characters in the current window of s2
            vector<int> windowCount(26, 0);

            // Count characters in the current window of s2
            for (int i = 0; i < s1.size(); i++)
            {
                windowCount[s2[start + i] - 'a']++;
            }

            // Compare character counts of s1 and the current window of s2
            if (charCount == windowCount)
            {
                return true; // Found a permutation of s1 in s2
            }

            // Slide the window by one character to the right
            start++;
            end++;
        }

        return false; // No permutation of s1 found in s2
    }
};
