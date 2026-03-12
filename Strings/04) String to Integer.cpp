class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int sign = 1;
        long result = 0;

        // 1. Skip spaces
        while(i < s.size() && s[i] == ' ')
            i++;

        // 2. Check sign
        if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')
                sign = -1;
            i++;
        }

        // 3. Read digits
        while(i < s.size() && isdigit(s[i])) {

            result = result * 10 + (s[i] - '0');

            // 4. Handle overflow
            if(sign * result >= INT_MAX)
                return INT_MAX;
            if(sign * result <= INT_MIN)
                return INT_MIN;

            i++;
        }

        return sign * result;
    }
};