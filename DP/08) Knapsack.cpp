class Solution {
public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= W; w++) {

                if(wt[i-1] <= w) {
                    dp[i][w] = max(
                        val[i-1] + dp[i-1][w - wt[i-1]],
                        dp[i-1][w]
                    );
                }
                else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }

        return dp[n][W];
    }
};


class Solution {
public:
    vector<int> knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // Fill DP table
        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= W; w++) {

                if(wt[i-1] <= w) {
                    dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]],
                                   dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }

        // Backtrack to find selected weights
        vector<int> result;
        int w = W;

        for(int i = n; i > 0; i--) {
            if(dp[i][w] != dp[i-1][w]) { // item included
                result.push_back(wt[i-1]);
                w -= wt[i-1];
            }
        }

        return result;
    }
};


Time Complexity
𝑂
(
𝑁
×
𝑊
)
O(N×W)

N = number of items

W = knapsack capacity

Space Complexity
𝑂
(
𝑁
×
𝑊
)
O(N×W)