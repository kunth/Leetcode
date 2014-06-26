class Solution {
public:
    int minval(int a, int b)
    {
        return a < b ? a : b;
    }
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(i==0 && j > 0)
                {
                    grid[i][j] += grid[i][j-1];
                }
                else if(j==0 && i>0)
                {
                    grid[i][j] += grid[i-1][j];
                }
                else if(i>0 && j>0)
                {
                    grid[i][j] += minval(grid[i-1][j] , grid[i][j-1]);
                }
            }
        }
        return grid[row-1][col-1];
    }
};

//SECOND TRIAL
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
            return 0;
        int row = grid.size(), col = grid[0].size();
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(!i && !j)
                    continue;
                else if(!j)
                    grid[i][j] += grid[i-1][j];
                else if(!i)
                    grid[i][j] += grid[i][j-1];
                else
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];
    }
};
