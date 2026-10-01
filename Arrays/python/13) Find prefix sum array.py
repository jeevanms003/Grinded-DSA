class Solution:
    def prefixSumArray(self, nums: list[int]) -> list[int]:
        n = len(nums)
        if n == 0:
            return []
            
        prefix = [0] * n
        prefix[0] = nums[0]

        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        return prefix


if __name__ == '__main__':
    pass
