class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        mp = {}
        result = []

        # Store elements of nums1
        for num in nums1:
            mp[num] = mp.get(num, 0) + 1

        # Check elements of nums2
        for num in nums2:
            if num in mp:
                result.append(num)
                del mp[num]   # remove to ensure uniqueness

        return result

class Solution2:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        s1 = set(nums1)
        s2 = set(nums2)
        
        result = []
        
        for num in s1:
            if num in s2:
                result.append(num)
                
        return result


if __name__ == '__main__':
    pass
