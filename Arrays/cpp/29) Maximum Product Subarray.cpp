#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            ans = max(ans, currMax);
        }

        return ans;
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
    cout << sol.maxProduct(nums) << endl;
    return 0;
}
