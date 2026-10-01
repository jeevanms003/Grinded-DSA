class Solution {
public:
    int firstNonRepeating(vector<int>& nums) {
        unordered_map<int, int> mp;

        // Step 1: Count frequency
        for(int num : nums) {
            mp[num]++;
        }

        // Step 2: Find first element with freq = 1
        for(int num : nums) {
            if(mp[num] == 1) {
                return num;
            }
        }

        return -1;  // if no non-repeating element
    }
};