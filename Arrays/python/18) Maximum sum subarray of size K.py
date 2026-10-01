class Solution:
    def maxSubarraySum(self, nums: list[int], k: int) -> int:
        n = len(nums)
        if n < k:
            return 0
        sum_val = 0

        # Step 1: first window
        for i in range(k):
            sum_val += nums[i]

        maxSum = sum_val

        # Step 2: slide window
        for i in range(k, n):
            sum_val += nums[i]        # add new
            sum_val -= nums[i - k]    # remove old
            maxSum = max(maxSum, sum_val)

        return maxSum


if __name__ == '__main__':
    pass
