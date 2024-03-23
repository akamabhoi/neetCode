class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            // Remove indices from the deque that are out of the current window
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }

            // Remove indices from the deque that have smaller values than the current element
            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            // Push the current index into the deque
            dq.push_back(i);

            // If the current window size is equal to k, append the maximum element to the answer
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};