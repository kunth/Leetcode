#388ms
class Solution:
    # @return an integer
    def maxArea(self, height):
        i = ans = 0
        j = len(height)-1
        while i < j:
            if ans < min(height[i], height[j]) * (j-i):
                ans = min(height[i], height[j]) * (j-i)
            if height[i] <= height[j]:
                i+=1
            else:
                j-=1
        return ans
