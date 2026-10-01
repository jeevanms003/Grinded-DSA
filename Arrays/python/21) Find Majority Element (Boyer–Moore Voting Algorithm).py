class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        candidate = 0
        count = 0

        for num in nums:
            if count == 0:
                candidate = num

            if num == candidate:
                count += 1
            else:
                count -= 1

        return candidate

class Solution2:
    def majorityElement(self, nums: list[int]) -> int:
        mp = {}
        n = len(nums)

        for num in nums:
            mp[num] = mp.get(num, 0) + 1

            if mp[num] > n // 2:
                return num

        return -1 # safety return


if __name__ == '__main__':
    pass
