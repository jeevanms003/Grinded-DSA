class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        j = 0  # Position for next non-zero element
        
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1
