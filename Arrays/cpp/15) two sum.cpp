#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;   // value -> index
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            
            mp[nums[i]] = i;
        }
        
        return {};  // not found (won’t happen in LC)
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
    int target;
    cin >> target;
    vector<int> res = sol.twoSum(nums, target);
    for(int x : res) cout << x << ' ';
    cout << endl;
    return 0;
}
