#include <iostream>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefixSum = 0;
        int count = 0;
        
        mp[0] = 1;  // Important
        
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            if(mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }
            
            mp[prefixSum]++;
        }
        
        return count;
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
    cout << sol.subarraySum(nums, k) << endl;
    return 0;
}
