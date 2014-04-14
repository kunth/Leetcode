class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>>dp;
        for(int i = 0; i<row; ++i)
        {
            vector<int>vec(col, 0);
            dp.push_back(vec);
            for(int j=0; j<col; ++j)
            {
                if(j==0)
                    dp[i][j] = matrix[i][j]=='1' ? 1 : 0;
                else
                    dp[i][j] = matrix[i][j]=='1' ? dp[i][j-1] + 1 : 0;
            }
        }
        int ans = 0;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                int width = dp[i][j];
                if(width>0)
                {
                    for(int cnt = i; cnt>=0 && width>0; --cnt)
                    {
                        width = min(width, dp[cnt][j]);
                        ans = max(ans, width*(i-cnt+1));
                    }
                }
            }
        }
        return ans;
    }
};
