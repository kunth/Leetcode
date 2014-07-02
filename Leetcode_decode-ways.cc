class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0')
            return 0;
        vector<int>dp(s.length()+1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i<=s.length(); ++i)
        {
            if(s[i-1]!='0')
                dp[i] = dp[i-1];
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7'))
                dp[i] += dp[i-2];
        }
        return dp[s.length()];
    }
};

//Solution Two:
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(s.empty() || s[0]=='0')
            return 0;
        if(len==1)
            return s[0]!='0' ? 1 : 0;
        vector<int>dp(len, 1);
        if(s[1]=='0')
        {
            if(s[0]=='0' || s[0]>'2')
                return 0;
        }
        else if(s[0]=='1'|| (s[0]=='2' && s[1]<='6'))
            dp[1] = 2;
        for(int i = 2; i<len; ++i)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='0' || s[i-1]>'2')
                    return 0;
                else
                    dp[i] = dp[i-2];
            }
            else
            {
                dp[i] = dp[i-1];
                if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6'))
                    dp[i] += dp[i-2];
            }
        }
        return dp[len-1];
    }
};
