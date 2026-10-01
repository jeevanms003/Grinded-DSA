class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;          // increase frequency

            if(mp[num] > 1) {   // if already seen
                return num;     // duplicate found
            }
        }

        return -1; // safety return
    }
};