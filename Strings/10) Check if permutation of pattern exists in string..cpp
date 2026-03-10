class Solution {
public:
    bool checkInclusion(string p, string s) {

        if (s.size() < p.size()) return false;

        unordered_map<char, int> mp;

        // Store frequency of pattern
        for (char c : p) {
            mp[c]++;
        }

        int left = 0;
        int count = p.size();

        for (int right = 0; right < s.size(); right++) {

            if (mp[s[right]] > 0) {
                count--;
            }

            mp[s[right]]--;

            // Maintain fixed window size
            if (right - left + 1 > p.size()) {

                if (mp[s[left]] >= 0) {
                    count++;
                }

                mp[s[left]]++;
                left++;
            }

            if (count == 0) {
                return true;
            }
        }

        return false;
    }
};