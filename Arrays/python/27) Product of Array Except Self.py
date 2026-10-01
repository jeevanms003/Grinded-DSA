class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        
        left = [0] * n
        right = [0] * n
        result = [0] * n

        # left array
        left[0] = 1
        for i in range(1, n):
            left[i] = left[i-1] * nums[i-1]

        # right array
        right[n-1] = 1
        for i in range(n-2, -1, -1):
            right[i] = right[i+1] * nums[i+1]

        # final result
        for i in range(n):
            result[i] = left[i] * right[i]

        return result

class Solution2:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        result = [0] * n

        # left products
        result[0] = 1
        for i in range(1, n):
            result[i] = result[i-1] * nums[i-1]

        # right products
        rightProduct = 1
        for i in range(n-1, -1, -1):
            result[i] = result[i] * rightProduct
            rightProduct *= nums[i]

        return result


if __name__ == '__main__':
    pass
