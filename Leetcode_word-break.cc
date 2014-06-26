class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.empty() || s.empty())
            return false;
       
        vector<bool>dp(s.length()+1, false);
        dp[0]=true;
        for(int i = 0; i<s.length(); ++i)
        {
            for(int j = 1; i+j<=s.length(); ++j)
            {
                if(dp[i] && dict.find(s.substr(i, j)) != dict.end())
                {
                    dp[i+j]=true;
                    if(dp[s.length()])
                        return true;
                }
            }
        }
        return false;
    }
};
