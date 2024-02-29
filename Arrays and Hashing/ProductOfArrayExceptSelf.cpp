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



//O(1) Space

class Solution {
public:
    // Function to find the product of all elements in the array except self
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        // Calculate prefix products
        ans[0] = 1; // Initialize the first element of the prefix product array
        for(int i = 1; i < n; i++){
            ans[i] = ans[i - 1] * nums[i - 1]; // Multiply the previous prefix product with the previous element of nums
        }
        
        // Calculate suffix products
        int suffix = 1; // Initialize the suffix product variable to 1
        for(int i = n - 1; i >= 0; i--){
            ans[i] *= suffix; // Multiply the corresponding prefix product with the current suffix product
            suffix *= nums[i]; // Update the suffix product by multiplying it with the current element of nums
        }
        
        // Return the final result
        return ans;
    }
};

