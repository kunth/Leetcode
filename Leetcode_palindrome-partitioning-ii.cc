class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if(len<=1)
            return 0;
        vector<vector<bool>>is_p(len+1, vector<bool>(len+1, false));
        vector<int>dp(len+1);
        for(int i = 0; i<=len; ++i)
            dp[i]=i-1;

        for(int i = 0; i<len; ++i)
        {
            for(int j = 0; j<=i; ++j)
            {
                if(i-j>=2 && s[i]==s[j] && is_p[j+1][i-1])
                {
                    is_p[i][j] = is_p[j][i] = true;
                    dp[i+1] = min(dp[i+1], 1+dp[j]);
                }
                else if(i-j<2 && s[i]==s[j])
                {
                    is_p[i][j] = is_p[j][i] = true;
                    dp[i+1] = min(dp[i+1], 1+dp[j]);
                }
            }
        }
        return dp[len];
    }
};
