class Solution {
public:
    // Function to check if the given vector contains any duplicate elements
    bool containsDuplicate(vector<int>& nums) {
        // Create an unordered map to store the frequency of each number
        unordered_map<int, int> mp;

        // Iterate through the vector
        for(auto num: nums){
            // If the number is already in the map, a duplicate is found
            if(mp[num] >= 1){
                return true;
            }

            // Increment the frequency count of the current number in the map
            mp[num]++;
        }

        // No duplicates found, return false
        return false;
    }
};
