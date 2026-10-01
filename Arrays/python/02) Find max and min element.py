import sys

def findMaximum(nums: list[int]) -> int:
    if nums:
        return max(nums)
    else:
        return -sys.maxsize - 1


def findMinimum(nums: list[int]) -> int:
    if nums:
        return min(nums)
    else:
        return sys.maxsize


if __name__ == '__main__':
    nums = list(map(int, input().split()))
    print(findMaximum(nums))
