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
