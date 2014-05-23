class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return s;
        int len = s.length(), maxlen = 0;
        string substr;
        for(int i = 0; i < len; ++i)
        {
            for(int j = 0; i-j>=0 && i+j<len; ++j)
            {
                if(s[i-j] != s[i+j])
                    break;
                if(maxlen < 2*j+1)
                {
                    maxlen = 2*j+1;
                    substr=s.substr(i-j, 2*j+1);
                }
            }
            for(int j = 0; i-j>=0 && i+j+1<len; ++j)
            {
                if(s[i-j] != s[i+j+1])
                    break;
                if(maxlen < 2*j+2)
                {
                    maxlen = 2*j+2;
                    substr = s.substr(i-j, 2*j+2);
                }
            }
        }
        return substr;
    }
};
