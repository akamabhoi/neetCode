class Solution {
public:
    // Function to find two numbers in the  given vector that sum up to the target value.
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Hash map to store the numbers and their indices.
        vector<int> ans; // Vector to store the indices of the two numbers that sum up to the target.

        // Iterating through the given vector.
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i]; // Calculating the complement needed to reach the target.

            // If the complement is found in the map, it means the current number plus the complement equals the target.
            if(mp.find(complement) != mp.end()){
                ans.push_back(mp[complement]); // Storing the index of the complement.
                ans.push_back(i); // Storing the index of the current number.
            }
            else{
                mp[nums[i]] = i; // Storing the current number and its index in the map.
            }
        }
        return ans; // Returning the vector containing the indices of the two numbers.
    }
};
