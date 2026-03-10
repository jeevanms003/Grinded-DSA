class Solution {
public:
    string removeDuplicates(string s) {
        vector<bool> seen(256, false);
        string result = "";

        for (char c : s) {
            if (!seen[c]) {
                result += c;
                seen[c] = true;
            }
        }

        return result;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        unordered_map<char, bool> mp;
        string result = "";

        for (char c : s) {
            if (mp[c] == false) {   // not seen before
                result += c;
                mp[c] = true;
            }
        }

        return result;
    }
};