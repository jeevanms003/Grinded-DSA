class NumArray:
    def __init__(self, nums: list[int]):
        n = len(nums)
        if n == 0:
            self.prefix = []
            return
            
        self.prefix = [0] * n
        self.prefix[0] = nums[0]
        
        for i in range(1, n):
            self.prefix[i] = self.prefix[i - 1] + nums[i]

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.prefix[right]
        
        return self.prefix[right] - self.prefix[left - 1]
