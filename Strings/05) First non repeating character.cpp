class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(256, 0);

        // First pass: count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Second pass: find first character with freq = 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;  // if no unique character
    }
};