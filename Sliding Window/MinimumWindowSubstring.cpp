class Solution
{
public:
    string minWindow(string s, string t)
    {
        // Create a frequency map for characters in the target string
        unordered_map<char, int> targetFreq;
        for (char c : t)
        {
            targetFreq[c]++;
        }

        // Initialize variables
        int left = 0, right = 0;             // Pointers for the sliding window
        int requiredChars = t.size();        // Number of unique characters in t that need to be found
        int minStart = 0, minLen = INT_MAX;  // Variables to store the minimum window
        unordered_map<char, int> windowFreq; // Frequency map for characters in the current window

        // Iterate through the string s with the sliding window
        while (right < s.size())
        {
            // Add the character at the right pointer to the window
            windowFreq[s[right]]++;

            // If the current character is in the target string and its frequency in the window is <= its frequency in the target,
            // decrement the number of required characters
            if (targetFreq.count(s[right]) && windowFreq[s[right]] <= targetFreq[s[right]])
            {
                requiredChars--;
            }

            // If all required characters have been found, try to shrink the window
            while (requiredChars == 0)
            {
                // Update the minimum window if the current window is smaller
                if (right - left + 1 < minLen)
                {
                    minStart = left;
                    minLen = right - left + 1;
                }

                // Remove the character at the left pointer from the window
                windowFreq[s[left]]--;

                // If the removed character was in the target string and its frequency in the window is now less than its frequency in the target,
                // increment the number of required characters
                if (targetFreq.count(s[left]) && windowFreq[s[left]] < targetFreq[s[left]])
                {
                    requiredChars++;
                }

                // Move the left pointer to shrink the window
                left++;
            }

            // Move the right pointer to expand the window
            right++;
        }

        // If no valid window was found, return an empty string
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};