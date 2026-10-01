#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> prefixSumArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);

        prefix[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        return prefix;
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
    vector<int> res = sol.prefixSumArray(nums);
    for(int x : res) cout << x << ' ';
    cout << endl;
    return 0;
}
