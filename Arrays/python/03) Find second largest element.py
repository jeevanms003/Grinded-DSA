import sys

def findSecondLargest(nums: list[int]) -> int:
    if len(nums) < 2:
        return -1
        
    first = -sys.maxsize - 1
    second = -sys.maxsize - 1
    
    for num in nums:
        if num > first:
            second = first
            first = num
        elif num > second and num != first:
            second = num
            
    if second == -sys.maxsize - 1:
        return -1
        
    return second

def findSecondSmallest(nums: list[int]) -> int:
    if len(nums) < 2:
        return -1
        
    first = sys.maxsize
    second = sys.maxsize
    
    for num in nums:
        if num < first:
            second = first
            first = num
        elif num < second and num != first:
            second = num
            
    if second == sys.maxsize:
        return -1
        
    return second


if __name__ == '__main__':
    pass
