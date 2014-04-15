class Solution {
public:
    int numDistinct(string S, string T) {
        if(S.empty() || S.length() < T.length())
            return 0;
        vector<vector<int>>dp;
        for(int i=0; i<=S.length(); ++i)
        {
            vector<int>tmpvec(T.length()+1, 0);
            dp.push_back(tmpvec);
        }
        for(int i = 1; i<=S.length(); ++i)
        {
            for(int j = 1; j<=i && j<=T.length(); ++j)
            {
                if(S[i-1]==T[j-1])
                {
                    if(i==1 || j==1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i-1][j-1];
                }
                if(j<i)//j<=i is also OK, but at that time dp[i-1][j] all equals to zero.
                {
                    dp[i][j]+=dp[i-1][j];
                }
            }
        }
        return dp[S.length()][T.length()];
    }
};
