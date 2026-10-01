#include <vector>
#include <climits>
using namespace std;

int findSecondLargest(vector<int>& nums) {
    if (nums.size() < 2)
        return -1;

    int first = INT_MIN;
    int second = INT_MIN;

    for (int num : nums) {
        if (num > first) {
            second = first;
            first = num;
        }
        else if (num > second && num != first) {
            second = num;
        }
    }

    if (second == INT_MIN)
        return -1;

    return second;
}

#include <vector>
#include <climits>
using namespace std;

int findSecondSmallest(vector<int>& nums) {
    if (nums.size() < 2)
        return -1;

    int first = INT_MAX;
    int second = INT_MAX;

    for (int num : nums) {
        if (num < first) {
            second = first;
            first = num;
        }
        else if (num < second && num != first) {
            second = num;
        }
    }

    if (second == INT_MAX)
        return -1;

    return second;
}