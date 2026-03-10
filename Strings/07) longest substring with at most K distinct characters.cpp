class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;

        vector<int> freq(256, 0);
        int left = 0;
        int maxLen = 0;
        int distinct = 0;

        for (int right = 0; right < s.length(); right++) {

            if (freq[s[right]] == 0) {
                distinct++;
            }

            freq[s[right]]++;

            while (distinct > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    distinct--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};