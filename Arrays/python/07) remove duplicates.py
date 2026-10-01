class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0
            
        j = 0  # Index of last unique element
        
        for i in range(1, len(nums)):
            if nums[i] != nums[j]:
                j += 1
                nums[j] = nums[i]
                
        return j + 1  # New length

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    print(Solution().removeDuplicates(nums))
