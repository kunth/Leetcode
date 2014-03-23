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
