#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leftRotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;   // Handle k > n

    // Step 1: Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 2: Reverse remaining elements
    reverse(nums.begin() + k, nums.end());

    // Step 3: Reverse entire array
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
    int k;
    cin >> k;
    sol.leftRotate(nums, k);
    for(int x : nums) cout << x << ' ';
    cout << endl;
    return 0;
}
