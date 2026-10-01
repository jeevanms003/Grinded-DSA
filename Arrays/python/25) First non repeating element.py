class Solution:
    def firstNonRepeating(self, nums: list[int]) -> int:
        mp = {}

        # Step 1: Count frequency
        for num in nums:
            mp[num] = mp.get(num, 0) + 1

        # Step 2: Find first element with freq = 1
        for num in nums:
            if mp[num] == 1:
                return num

        return -1  # if no non-repeating element

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    print(Solution().firstNonRepeating(nums))
