class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        if not obstacleGrid:
            return 0
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        if obstacleGrid[0][0] or obstacleGrid[row-1][col-1]:
            return 0
        for i in range(0, row):
            if not obstacleGrid[i][0]:
                obstacleGrid[i][0] = -1
            else:
                break
        for i in range(1, col):
            if not obstacleGrid[0][i]:
                obstacleGrid[0][i] = -1
            else:
                break
        for i in range(1, row):
            for j in range(1, col):
                if obstacleGrid[i][j]:
                    continue
                if obstacleGrid[i-1][j] < 0:
                    obstacleGrid[i][j] += obstacleGrid[i-1][j]
                if obstacleGrid[i][j-1] < 0:
                    obstacleGrid[i][j] += obstacleGrid[i][j-1]
        return -obstacleGrid[row-1][col-1]
