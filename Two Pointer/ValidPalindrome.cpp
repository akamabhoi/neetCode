// Class Solution to implement the isPalindrome function
class Solution
{
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(string s)
    {
        // If the string is empty, it is considered a palindrome
        if (s == "")
            return true;

        // Get the size of the string
        int n = s.size();
        // Initialize pointers to the beginning and end of the string
        int left = 0;
        int right = n - 1;

        // Loop until the left pointer is less than the right pointer
        while (left < right)
        {
            // If the character at the left pointer is not alphanumeric, move the left pointer to the right
            if (!isalnum(s[left]))
            {
                left++;
                continue;
            }

            // If the character at the right pointer is not alphanumeric, move the right pointer to the left
            if (!isalnum(s[right]))
            {
                right--;
                continue;
            }

            // If the lowercase characters at the left and right pointers are not equal, the string is not a palindrome
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            // Move both pointers towards each other
            left++;
            right--;
        }

        // If the loop completes without returning false, the string is a palindrome
        return true;
    }
};
