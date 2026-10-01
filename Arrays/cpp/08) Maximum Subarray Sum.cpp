#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            
            maxSum = max(maxSum, currSum);
            
            if(currSum < 0) {
                currSum = 0;
            }
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
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}
