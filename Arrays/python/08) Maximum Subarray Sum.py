class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        currSum = 0
        maxSum = nums[0]
        
        for i in range(len(nums)):
            currSum += nums[i]
            
            maxSum = max(maxSum, currSum)
            
            if currSum < 0:
                currSum = 0
                
        return maxSum

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    print(Solution().maxSubArray(nums))
