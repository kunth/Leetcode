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

//Second trial, almost the same
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty() || dict.empty())
            return NULL;
        vector<bool>dp(s.length()+1, false);
        dp[0] = true;
        int wlen;
        for(int i = 0; i<s.length(); ++i) {
            for(auto it = dict.begin(); it != dict.end(); ++it) {
                wlen = (*it).length();
                if(dp[i]) {
                    if(i + wlen <= s.length() && s.substr(i, wlen)==*it)
                        dp[i+wlen] = true;
                }
            }
            if(dp[s.length()])
                return true;
        }
        return false;
    }
};
