class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0]==1)
            return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[row-1][col-1]==1)
            return 0;
        obstacleGrid[0][0] = 1;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if((i||j) && obstacleGrid[i][j]==1)
                {
                    obstacleGrid[i][j]=0;
                    continue;
                }
                if(i==0 && j>0)
                {
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                }
                else if(j==0 && i>0)
                {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                }
                else if(i>0 && j>0)
                {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[row-1][col-1];
    }
};
