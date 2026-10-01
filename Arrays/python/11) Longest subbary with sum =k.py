class Solution:
    def longestSubarray(self, nums: list[int], K: int) -> int:
        mp = {}   # prefixSum -> first index
        sum_val = 0
        maxLen = 0

        for i in range(len(nums)):
            sum_val += nums[i]

            if sum_val == K:
                maxLen = i + 1

            if (sum_val - K) in mp:
                length = i - mp[sum_val - K]
                maxLen = max(maxLen, length)

            # Store first occurrence only
            if sum_val not in mp:
                mp[sum_val] = i

        return maxLen

class Solution2:
    def longestSubarray(self, nums: list[int], K: int) -> int:
        left = 0
        sum_val = 0
        maxLen = 0

        for right in range(len(nums)):
            sum_val += nums[right]

            while sum_val > K:
                sum_val -= nums[left]
                left += 1

            if sum_val == K:
                maxLen = max(maxLen, right - left + 1)

        return maxLen


if __name__ == '__main__':
    pass
