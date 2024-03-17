// This function finds the median of two sorted arrays.
// It takes two vectors of integers as input.
// It concatenates the two vectors, sorts the resulting vector, and then calculates the median.
// If the combined size of the two vectors is odd, it returns the middle element.
// If the combined size of the two vectors is even, it returns the average of the two middle elements.
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // Create a vector to store the concatenated elements of nums1 and nums2
    vector<int> ans;

    // Copy the elements of nums1 into the ans vector
    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(nums1[i]);
    }

    // Copy the elements of nums2 into the ans vector
    for (int i = 0; i < nums2.size(); i++)
    {
        ans.push_back(nums2[i]);
    }

    // Sort the ans vector
    sort(ans.begin(), ans.end());

    // Get the size of the ans vector
    int n = ans.size();

    // Check if the size of the ans vector is odd
    if (n % 2 == 1)
    {
        // If odd, return the middle element
        return double(ans[n / 2]);
    }
    else
    {
        // If even, calculate the average of the two middle elements and return
        int middle1 = ans[n / 2];
        int middle2 = ans[n / 2 - 1];
        return double((middle1 + middle2) / 2.0);
    }
}
