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