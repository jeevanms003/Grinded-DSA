class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums) + 1   # since one number is missing
        
        expectedSum = n * (n + 1) // 2
        actualSum = sum(nums)
        
        return expectedSum - actualSum

class Solution2:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums) + 1
        xor1 = 0
        xor2 = 0

        # XOR from 1 to n
        for i in range(1, n + 1):
            xor1 ^= i

        # XOR all array elements
        for num in nums:
            xor2 ^= num

        return xor1 ^ xor2

class Solution3:
    def missingNumber0ToN(self, nums: list[int]) -> int:
        n = len(nums)   # because range is 0 to n
        
        expectedSum = n * (n + 1) // 2
        actualSum = sum(nums)
        
        return expectedSum - actualSum

class Solution4:
    def missingNumber0ToNXor(self, nums: list[int]) -> int:
        n = len(nums)   # range is 0 to n
        xor1 = 0
        xor2 = 0

        # XOR from 0 to n
        for i in range(n + 1):
            xor1 ^= i

        # XOR all array elements
        for num in nums:
            xor2 ^= num

        return xor1 ^ xor2

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    print(Solution().missingNumber(nums))
