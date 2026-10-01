class Solution {
public:
    int maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        // Step 1: first window
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        int maxSum = sum;

        // Step 2: slide window
        for(int i = k; i < n; i++) {
            sum += nums[i];        // add new
            sum -= nums[i - k];    // remove old
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};