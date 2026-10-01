class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        if not nums:
            return 0
            
        currMax = nums[0]
        currMin = nums[0]
        ans = nums[0]

        for i in range(1, len(nums)):
            if nums[i] < 0:
                currMax, currMin = currMin, currMax

            currMax = max(nums[i], currMax * nums[i])
            currMin = min(nums[i], currMin * nums[i])

            ans = max(ans, currMax)

        return ans

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    print(Solution().maxProduct(nums))
