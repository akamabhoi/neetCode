class Solution {
public:
    // Function to find the top k frequent elements in the given vector
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create an unordered map to store the frequency of each element
        unordered_map<int, int> mp;
        
        // Create a vector to store the answer
        vector<int> ans;
        
        // Count the frequency of each element
        for(auto num: nums){
            mp[num]++;
        }
        
        // Convert the unordered_map to a vector of pairs for sorting
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        
        // Sort the vector based on the frequency of elements in descending order
        sort(vec.begin(), vec.end(), [](auto& lhs, auto& rhs ){
            return lhs.second > rhs.second;
        });
        
        // Push the top k frequent elements into the answer vector
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].first);
        }
        
        // Return the answer vector
        return ans;
    }
};
