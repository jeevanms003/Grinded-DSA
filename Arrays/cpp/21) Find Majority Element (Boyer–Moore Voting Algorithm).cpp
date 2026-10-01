#include <iostream>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for(int num : nums) {
            if(count == 0) {
                candidate = num;
            }

            if(num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int num : nums) {
            mp[num]++;

            if(mp[num] > n / 2) {
                return num;
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
    cout << sol.majorityElement(nums) << endl;
    return 0;
}
