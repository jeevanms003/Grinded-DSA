class Solution:

    def findSecondLargest(self, nums):
        if len(nums) < 2:
            return -1

        nums = list(set(nums))
        nums.sort()

        return nums[-2]

    def findSecondSmallest(self, nums):
        if len(nums) < 2:
            return -1

        nums = list(set(nums))
        nums.sort()

        return nums[1]
