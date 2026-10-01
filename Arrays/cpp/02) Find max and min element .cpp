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