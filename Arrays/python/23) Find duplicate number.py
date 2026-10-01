class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        mp = {}

        for num in nums:
            mp[num] = mp.get(num, 0) + 1  # increase frequency

            if mp[num] > 1:               # if already seen
                return num                # duplicate found

        return -1 # safety return


if __name__ == '__main__':
    pass
