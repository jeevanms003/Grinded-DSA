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