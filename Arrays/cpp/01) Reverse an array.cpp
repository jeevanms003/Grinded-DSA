#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }
    }
};



#include <vector>
#include <algorithm>
using namespace std;

vector<int> reverseArray(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        swap(nums[left], nums[right]);
        left++;
        right--;
    }

    return nums;
}


#include <algorithm>

void reverseArray(vector<int>& nums) {
    reverse(nums.begin(), nums.end());
}

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    int n_nums;
    cin >> n_nums;
    vector<int> nums(n_nums);
    for(int i=0; i<n_nums; i++) cin >> nums[i];
    sol.reverseArray(nums);
    for(int x : nums) cout << x << ' ';
    cout << endl;
    return 0;
}
