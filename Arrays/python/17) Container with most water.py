class Solution:
    def maxArea(self, height: list[int]) -> int:
        left = 0
        right = len(height) - 1
        maxWater = 0

        while left < right:
            h = min(height[left], height[right])
            width = right - left
            area = h * width

            maxWater = max(maxWater, area)

            # Move smaller height
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxWater
