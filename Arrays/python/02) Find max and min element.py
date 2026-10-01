import sys

def findMaximum(nums: list[int]) -> int:
    return max(nums) if nums else -sys.maxsize - 1

def findMinimum(nums: list[int]) -> int:
    return min(nums) if nums else sys.maxsize

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    print(findMaximum(nums))
