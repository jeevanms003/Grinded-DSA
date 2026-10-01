#include <iostream>
using namespace std;
class Solution {
public:
    int equilibriumIndex(vector<int>& nums) {
        int total = 0;
        
        for(int x : nums)
            total += x;

        int leftSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            int rightSum = total - leftSum - nums[i];

            if(leftSum == rightSum)
                return i;

            leftSum += nums[i];
        }

        return -1;  // no equilibrium index
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
    cout << sol.equilibriumIndex(nums) << endl;
    return 0;
}
