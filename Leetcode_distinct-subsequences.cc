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

//SEDNOD TRIAL
class Solution {
public:
    int numDistinct(string S, string T) {
        int sl = S.length(), tl = T.length();
        if(sl < tl || tl==0)
            return 0;
        vector<vector<int> >dp;
        for(int i = 0; i<tl; ++i)
        {
            vector<int>v(sl, 0);
            dp.push_back(v);
        }
        for(int i = 0; i<tl; ++i)
        {
            for(int j = i; j<sl; ++j)
            {
                if(!i)
                {
                    if(!j)
                        dp[i][j] = (S[j]==T[i]);
                    else
                        dp[i][j] = dp[i][j-1] + (S[j]==T[i]);
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                    if(S[j]==T[i] && dp[i-1][j-1])
                        dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[tl-1][sl-1];
    }
};
