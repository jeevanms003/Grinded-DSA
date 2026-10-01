class Solution {
public:
    int longestSubarray(vector<int>& nums, int K) {
        unordered_map<int,int> mp;   // prefixSum -> first index
        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum == K)
                maxLen = i + 1;

            if(mp.find(sum - K) != mp.end()) {
                int len = i - mp[sum - K];
                maxLen = max(maxLen, len);
            }

            // Store first occurrence only
            if(mp.find(sum) == mp.end())
                mp[sum] = i;
        }

        return maxLen;
    }
};



class Solution {
public:
    int longestSubarray(vector<int>& nums, int K) {
        int left = 0, sum = 0, maxLen = 0;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum > K) {
                sum -= nums[left];
                left++;
            }

            if(sum == K)
                maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};