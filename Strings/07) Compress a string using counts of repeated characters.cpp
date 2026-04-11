class Solution {
public:
    string compressString(string s) {
        string res = "";
        int n = s.size();

        for(int i = 0; i < n; i++) {
            int count = 1;

            // count duplicates
            while(i + 1 < n && s[i] == s[i + 1]) {
                count++;
                i++;
            }

            // append char + count
            res += s[i];
            res += to_string(count);
        }

        return res;
    }
};