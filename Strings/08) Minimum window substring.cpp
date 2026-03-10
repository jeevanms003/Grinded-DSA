class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size()) return "";

        unordered_map<char, int> mp;

        // Step 1: Store frequency of t
        for (char c : t) {
            mp[c]++;
        }

        int left = 0;
        int count = t.size();      // characters still needed
        int minLen = INT_MAX;
        int start = 0;

        // Step 2: Expand window
        for (int right = 0; right < s.size(); right++) {

            if (mp[s[right]] > 0) {
                count--;
            }

            mp[s[right]]--;

            // Step 3: When valid window found
            while (count == 0) {

                // Update minimum
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Shrink window
                mp[s[left]]++;

                if (mp[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};