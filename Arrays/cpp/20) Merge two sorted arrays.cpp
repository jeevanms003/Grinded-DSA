#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> mergeArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        vector<int> result;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        // Remaining elements
        while(i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    int n_nums1;
    cin >> n_nums1;
    vector<int> nums1(n_nums1);
    for(int i=0; i<n_nums1; i++) cin >> nums1[i];
    int n_nums2;
    cin >> n_nums2;
    vector<int> nums2(n_nums2);
    for(int i=0; i<n_nums2; i++) cin >> nums2[i];
    vector<int> res = sol.mergeArrays(nums1, nums2);
    for(int x : res) cout << x << ' ';
    cout << endl;
    return 0;
}
