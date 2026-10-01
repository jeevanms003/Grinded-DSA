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