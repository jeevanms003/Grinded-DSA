def leftRotate(nums: list[int], k: int) -> None:
    n = len(nums)
    if n == 0:
        return
    k = k % n   # Handle k > n
    
    # Step 1: Reverse first k elements
    nums[:k] = reversed(nums[:k])
    
    # Step 2: Reverse remaining elements
    nums[k:] = reversed(nums[k:])
    
    # Step 3: Reverse entire array
    nums[:] = reversed(nums[:])


if __name__ == '__main__':
    pass
