def isSorted(nums: list[int]) -> bool:
    for i in range(1, len(nums)):
        if nums[i] < nums[i - 1]:
            return False
    return True

class Solution:
    def check(self, nums: list[int]) -> bool:
        n = len(nums)
        count = 0
        
        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                count += 1
                
        return count <= 1
