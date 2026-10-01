class Solution:
    def reverseArray(self, nums: list[int]) -> None:
        left = 0
        right = len(nums) - 1
        
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

def reverseArrayInbuilt(nums: list[int]) -> None:
    nums.reverse()

nums = list(map(int, input().split()))

# Create object
obj = Solution()

# Call function
obj.reverseArray(nums)

# Output
print(nums)


if __name__ == '__main__':
    pass
