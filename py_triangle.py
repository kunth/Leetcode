class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        if not triangle:
            return 0
        sz = len(triangle)
        for i in range(1, sz):
            for j in range(0, i+1):
                if not j:
                    triangle[i][j] += triangle[i-1][0]
                elif j == i:
                    triangle[i][j] += triangle[i-1][j-1]
                else:
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
        ans = triangle[sz-1][0]
        for i in range(1, sz):
            ans = min(ans, triangle[sz-1][i])
        return ans
