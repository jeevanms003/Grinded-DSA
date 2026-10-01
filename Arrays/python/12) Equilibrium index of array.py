class Solution:
    def equilibriumIndex(self, nums: list[int]) -> int:
        total = sum(nums)

        leftSum = 0

        for i in range(len(nums)):
            rightSum = total - leftSum - nums[i]

            if leftSum == rightSum:
                return i

            leftSum += nums[i]

        return -1  # no equilibrium index


if __name__ == '__main__':
    pass
