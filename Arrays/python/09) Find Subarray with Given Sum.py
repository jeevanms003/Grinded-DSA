class Solution:
    def subarraySum(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        left = 0
        sum_val = 0

        for right in range(n):
            sum_val += nums[right]

            while sum_val > target:
                sum_val -= nums[left]
                left += 1

            if sum_val == target:
                return [left, right]  # return indices

        return [-1, -1]  # not found

class Solution2:
    def subarraySum(self, nums: list[int], target: int) -> list[int]:
        mp = {}  # prefixSum -> index
        sum_val = 0

        for i in range(len(nums)):
            sum_val += nums[i]

            if sum_val == target:
                return [0, i]

            if (sum_val - target) in mp:
                return [mp[sum_val - target] + 1, i]

            mp[sum_val] = i

        return [-1, -1]

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    target = int(input())
    res = Solution().subarraySum(nums, target)
    print(' '.join(map(str, res)))
