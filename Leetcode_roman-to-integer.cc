class Solution {
public:
    inline int c2i(char ch)
    {
        switch(ch)
        {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
        }
    }
    int romanToInt(string s) {
        int len = s.length(), ans = c2i(s[0]), pre = 0, cur = 0;
        if(len==1)
            return ans;
        for(int i = 1; i<len; ++i)
        {
            pre = c2i(s[i-1]);
            cur = c2i(s[i]);
            if(pre >= cur)
                ans += cur;
            else
                ans += (cur - 2*pre);
        }
        return ans;
    }
};

//SECOND TRIAL
class Solution {
public:
    inline int c2n(char ch)
    {
        switch(ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int ans = 0, last = 0, cur = 0;
        for(int i = 0; i<s.length(); ++i)
        {
            cur = c2n(s[i]);
            ans += cur;
            if(i && cur>last)
                ans -= 2*last;
            last = cur;
        }
        return ans;
    }
};
