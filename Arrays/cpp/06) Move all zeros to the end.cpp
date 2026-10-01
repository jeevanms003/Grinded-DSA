#include <iostream>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // Position for next non-zero element
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
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
    sol.moveZeroes(nums);
    for(int x : nums) cout << x << ' ';
    cout << endl;
    return 0;
}
