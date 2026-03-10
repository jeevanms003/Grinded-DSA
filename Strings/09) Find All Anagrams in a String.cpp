class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;
        if (s.size() < p.size()) return result;

        unordered_map<char, int> mp;

        // Step 1: Store frequency of pattern
        for (char c : p) {
            mp[c]++;
        }

        int left = 0;
        int count = p.size();   // characters still needed

        // Step 2: Sliding window
        for (int right = 0; right < s.size(); right++) {

            if (mp[s[right]] > 0) {
                count--;
            }

            mp[s[right]]--;

            // If window size exceeds pattern size
            if (right - left + 1 > p.size()) {

                if (mp[s[left]] >= 0) {
                    count++;
                }

                mp[s[left]]++;
                left++;
            }

            // If all characters matched
            if (count == 0) {
                result.push_back(left);
            }
        }

        return result;
    }
};