#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaximum(vector<int>& nums) {
    int maxi = INT_MIN;

    for (int num : nums) {
        if (num > maxi) {
            maxi = num;
        }
    }

    return maxi;
}


#include <vector>
#include <climits>
using namespace std;

int findMinimum(vector<int>& nums) {
    int mini = INT_MAX;

    for (int num : nums) {
        if (num < mini) {
            mini = num;
        }
    }

    return mini;
}

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    int n_nums;
    cin >> n_nums;
    vector<int> nums(n_nums);
    for(int i=0; i<n_nums; i++) cin >> nums[i];
    cout << sol.findMaximum(nums) << endl;
    return 0;
}
