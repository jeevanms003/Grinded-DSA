class Solution:
    def reverseArray(self, nums):
        left = 0
        right = len(nums) - 1

        while left < right:
            nums[left], nums[right] = nums[right], nums[left]

            left += 1
            right -= 1


class Solution:
    def reverseArray(self, nums):
        nums.reverse()
        return nums

  
