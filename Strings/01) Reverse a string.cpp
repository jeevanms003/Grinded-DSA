class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};


class Solution {
public:
    string reverseString(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

class Solution {
public:
    string reverseString(string s) {
        stack<char> st;

        // Push all characters
        for (char c : s) {
            st.push(c);
        }

        // Pop back into string
        int i = 0;
        while (!st.empty()) {
            s[i] = st.top();
            st.pop();
            i++;
        }

        return s;
    }
};