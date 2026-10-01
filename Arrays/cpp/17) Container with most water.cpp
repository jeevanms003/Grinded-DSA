#include <iostream>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while(left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            int area = h * width;

            maxWater = max(maxWater, area);

            // Move smaller height
            if(height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    int n_height;
    cin >> n_height;
    vector<int> height(n_height);
    for(int i=0; i<n_height; i++) cin >> height[i];
    cout << sol.maxArea(height) << endl;
    return 0;
}
