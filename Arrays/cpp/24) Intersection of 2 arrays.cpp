#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> result;

        // Store elements of nums1
        for(int num : nums1) {
            mp[num]++;
        }

        // Check elements of nums2
        for(int num : nums2) {
            if(mp.count(num)) {
                result.push_back(num);
                mp.erase(num);   // remove to ensure uniqueness
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        vector<int> result;
        
        for(int num : s1) {
            if(s2.count(num)) {
                result.push_back(num);
            }
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
    vector<int> res = sol.intersection(nums1, nums2);
    for(int x : res) cout << x << ' ';
    cout << endl;
    return 0;
}
