#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int j = 0;  // Index of last unique element
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        
        return j + 1;  // New length
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
    cout << sol.removeDuplicates(nums) << endl;
    return 0;
}
