class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        // Count characters from s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Subtract using t
        for (char c : t) {
            freq[c - 'a']--;
        }

        // Check if all counts are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(256, 0);

        // Count characters from s
        for (char c : s) {
            freq[c]++;
        }

        // Subtract using t
        for (char c : t) {
            freq[c]--;
        }

        // Check if all counts are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};