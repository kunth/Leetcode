class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        vector<bool>flag(s.length(), false);
        for(int i = 0; i<s.length(); ++i)
        {
            if(s[i]==')')
            {
                int j = i-1;
                while(j>=0 && flag[j])
                    --j;
                if(j>=0 && s[j]=='(')
                {
                    flag[i] = flag[j] = true;
                }
            }
        }
        int ans = 0, len = 0;
        for(int i = 0; i<flag.size(); ++i)
        {
            if(flag[i])
            {
                while(i<flag.size() && flag[i])
                {
                    ++len;
                    ++i;
                }
                ans = max(ans, len);
                len = 0;
            }
        }
        return ans;
    }
};
