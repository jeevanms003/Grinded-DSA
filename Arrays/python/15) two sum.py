class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp = {}   # value -> index
        
        for i in range(len(nums)):
            complement = target - nums[i]
            
            if complement in mp:
                return [mp[complement], i]
            
            mp[nums[i]] = i
            
        return []  # not found (won’t happen in LC)


if __name__ == '__main__':
    pass
