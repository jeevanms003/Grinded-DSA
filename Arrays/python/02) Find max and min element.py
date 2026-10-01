import sys

def findMaximum(nums: list[int]) -> int:
    maxi = -sys.maxsize - 1
    
    for num in nums:
        if num > maxi:
            maxi = num
            
    return maxi

def findMinimum(nums: list[int]) -> int:
    mini = sys.maxsize
    
    for num in nums:
        if num < mini:
            mini = num
            
    return mini
