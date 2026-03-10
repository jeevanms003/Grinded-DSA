class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int totalSum = 0;
        for(int num : nums)
            totalSum += num;

        if((target + totalSum) % 2 != 0 || abs(target) > totalSum)
            return 0;

        int sum = (target + totalSum) / 2;

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {

                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];

            }
        }

        return dp[n][sum];
    }
};