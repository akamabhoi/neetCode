//O(n) extra space
class Solution {
public:
    // Function to find the product of all elements in the array except self
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize arrays to store prefix and suffix products
        vector<int> ans(n, 1);   // Final result array
        vector<int> pre(n, 1);   // Array to store prefix products
        vector<int> suff(n, 1);  // Array to store suffix products
        
        // Calculate prefix products
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]*nums[i-1]; 
        }
        
        // Calculate suffix products
        for(int i=n-2; i>=0; i--){
            suff[i] = suff[i+1]*nums[i+1]; 
        }
        
        // Calculate result by multiplying prefix and suffix products
        for(int i=0; i<n; i++){
            ans[i] = pre[i]*suff[i];
        }
        
        // Return the final result
        return ans;
    }
};
