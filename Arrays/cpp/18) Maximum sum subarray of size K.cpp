#include <iostream>
using namespace std;
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

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    int n_nums;
    cin >> n_nums;
    vector<int> nums(n_nums);
    for(int i=0; i<n_nums; i++) cin >> nums[i];
    int k;
    cin >> k;
    cout << sol.maxSubarraySum(nums, k) << endl;
    return 0;
}
