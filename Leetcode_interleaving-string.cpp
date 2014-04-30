class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3)
            return false;
        if(s1.empty())
            return s2==s3;
        if(s2.empty())
            return s1==s3;
        vector<vector<bool> >dp;
        for(int i = 0; i<=len1; ++i)
        {
            vector<bool>tmpvec;
            for(int j = 0; j<=len2; ++j)
                tmpvec.push_back(false);
            dp.push_back(tmpvec);
        }
        for(int i = 0; i<len1; ++i)
            dp[i+1][0] = (s1[i]==s3[i]);
        for(int i = 0; i<len2; ++i)
            dp[0][i+1] = (s2[i]==s3[i]);
        for(int i = 1; i<=len1; ++i)
        {
            for(int j = 1; j<=len2; ++j)
            {
                dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i-1+j]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[len1][len2];
    }
};
