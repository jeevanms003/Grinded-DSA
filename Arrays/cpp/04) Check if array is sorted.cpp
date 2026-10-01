#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
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
    cout << sol.check(nums) << endl;
    return 0;
}
