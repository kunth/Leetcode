class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        col = [1]*n
        ans = [col]*m
        for i in range(1, m):
            for j in range(1, n):
                ans[i][j] = ans[i-1][j] + ans[i][j-1]
        return ans[m-1][n-1]
