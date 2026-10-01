#include <iostream>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1) {
                mid++;
            }

            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
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
    sol.sortColors(nums);
    for(int x : nums) cout << x << ' ';
    cout << endl;
    return 0;
}
