#include <iostream>
using namespace std;
class Solution {
public:
    int firstNonRepeating(vector<int>& nums) {
        unordered_map<int, int> mp;

        // Step 1: Count frequency
        for(int num : nums) {
            mp[num]++;
        }

        // Step 2: Find first element with freq = 1
        for(int num : nums) {
            if(mp[num] == 1) {
                return num;
            }
        }

        return -1;  // if no non-repeating element
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
    cout << sol.firstNonRepeating(nums) << endl;
    return 0;
}
