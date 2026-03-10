class Solution {
public:
    vector<int> subarraySum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int sum = 0;

        for(int right = 0; right < n; right++) {
            sum += nums[right];

            while(sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                return {left, right};  // return indices
            }
        }

        return {-1, -1};  // not found
    }
};



class Solution {
public:
    vector<int> subarraySum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;  // prefixSum -> index
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum == target)
                return {0, i};

            if(mp.find(sum - target) != mp.end())
                return {mp[sum - target] + 1, i};

            mp[sum] = i;
        }

        return {-1, -1};
    }
};