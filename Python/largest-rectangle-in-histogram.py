class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
        if not height: return 0
        elif len(height)==1:return height[0]
        i = 0
        ans = 0
        flag = False
        while i < len(height) and not flag:
            while i<len(height)-1 and height[i] <= height[i+1]:
                i += 1
            if i == len(height)-1:
                flag = True
            min_height = height[i]
            for j in range(i, -1, -1):
                min_height = min(min_height, height[j])
                ans = max(ans, min_height*(i-j+1))
            i+=1
        return ans
        
