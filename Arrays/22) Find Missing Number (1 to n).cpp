class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;   // since one number is missing
        
        long long expectedSum = (long long)n * (n + 1) / 2;
        long long actualSum = 0;
        
        for(int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int xor1 = 0, xor2 = 0;

        // XOR from 1 to n
        for(int i = 1; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR all array elements
        for(int num : nums) {
            xor2 ^= num;
        }

        return xor1 ^ xor2;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();   // because range is 0 to n
        
        long long expectedSum = (long long)n * (n + 1) / 2;
        long long actualSum = 0;
        
        for(int num : nums) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();   // range is 0 to n
        int xor1 = 0, xor2 = 0;

        // XOR from 0 to n
        for(int i = 0; i <= n; i++) {
            xor1 ^= i;
        }

        // XOR all array elements
        for(int num : nums) {
            xor2 ^= num;
        }

        return xor1 ^ xor2;
    }
};