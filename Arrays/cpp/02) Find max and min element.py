class Solution:

    def findMaximum(self, nums):
        maxi = float('-inf')

        for num in nums:
            if num > maxi:
                maxi = num

        return maxi

    def findMinimum(self, nums):
        mini = float('inf')

        for num in nums:
            if num < mini:
                mini = num

        return mini


class Solution:

    def findMaximum(self, nums):
        return max(nums)

    def findMinimum(self, nums):
        return min(nums)
