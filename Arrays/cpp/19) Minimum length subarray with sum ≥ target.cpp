#include <iostream>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    int target;
    cin >> target;
    int n_nums;
    cin >> n_nums;
    vector<int> nums(n_nums);
    for(int i=0; i<n_nums; i++) cin >> nums[i];
    cout << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}
