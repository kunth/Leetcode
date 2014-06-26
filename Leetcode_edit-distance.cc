class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty())
            return word2.length();
        if(word2.empty())
            return word1.length();
        vector<vector<int>>dp;
        for(int i = 0; i<=word1.length(); ++i)
        {
            vector<int>tmpvec(word2.length()+1, 0);
            dp.push_back(tmpvec);
        }
        dp[0][0] = 0;
        for(int i = 1; i <= word1.length(); ++i)
            dp[i][0] = i;
        for(int i = 1; i <= word2.length(); ++i)
            dp[0][i] = i;
        for(int i = 1; i <= word1.length(); ++i)
        {
            for(int j = 1; j <= word2.length(); ++j)
            {
                dp[i][j]=min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1] + (word1[i-1]==word2[j-1] ? 0 : 1));
            }
        }
        return dp[word1.length()][word2.length()];
    }
};
