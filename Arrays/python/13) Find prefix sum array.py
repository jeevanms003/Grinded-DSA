from itertools import accumulate

class Solution:
    def prefixSumArray(self, nums: list[int]) -> list[int]:
        return list(accumulate(nums))

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    res = Solution().prefixSumArray(nums)
    print(' '.join(map(str, res)))
