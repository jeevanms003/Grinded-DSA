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