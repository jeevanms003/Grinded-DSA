class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        result = []
        nums.sort()

        for i in range(len(nums)):
            
            # Skip duplicate fixed elements
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = len(nums) - 1

            while left < right:
                sum_val = nums[i] + nums[left] + nums[right]

                if sum_val == 0:
                    result.append([nums[i], nums[left], nums[right]])

                    # Skip duplicates
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1
                elif sum_val < 0:
                    left += 1
                else:
                    right -= 1

        return result

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    res = Solution().threeSum(nums)
    for r in res:
        print(' '.join(map(str, r)))
