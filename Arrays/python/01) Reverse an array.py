class Solution:
    def reverseArray(self, nums: list[int]) -> None:
        left = 0
        right = len(nums) - 1
        
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

def reverseArray(nums: list[int]) -> list[int]:
    left = 0
    right = len(nums) - 1
    
    while left < right:
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1
        
    return nums

def reverseArrayInbuilt(nums: list[int]) -> None:
    nums.reverse()
