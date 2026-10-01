#include <iostream>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;          // increase frequency

            if(mp[num] > 1) {   // if already seen
                return num;     // duplicate found
            }
        }

        return -1; // safety return
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
    cout << sol.findDuplicate(nums) << endl;
    return 0;
}
