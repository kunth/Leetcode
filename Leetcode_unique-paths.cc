int A[101][101];

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        for(int i = 1; i<=100; ++i)
        {
            for(int j = 1; j <= 100; ++j)
            {
                if(i==1 || j == 1)
                {
                    A[i][j] = 1;
                }
                else
                {
                    A[i][j]=A[i-1][j] + A[i][j-1];
                }
            }
        }
        return A[m][n];
    }
};

//SECOND TRIAL
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n==1 || m==1)
            return 1;
        int** grid = new int*[m];
        for(int i = 0; i<m; ++i)
            grid[i] = new int[n];
        for(int i = 0; i<m; ++i)
            grid[i][0] = 1;
        for(int i = 0; i<n; ++i)
            grid[0][i] = 1;
        for(int i = 1; i<m; ++i)
            for(int j = 1; j<n; ++j)
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
        int ans = grid[m-1][n-1];
        delete []grid;
        return ans;
    }
};

//clean code
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)
            return 1;
        vector<vector<int> >dp(m, vector<int>(n, 1));
        for(int i = 1; i<m; ++i)
            for(int j = 1; j<n; ++j)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};
