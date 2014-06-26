class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s), res = 0;
        for(int i = len -1; i>=0; --i)
        {
            if(res && s[i]==' ')
            {
                return res;
            }
            if(s[i] != ' ')
            {
                ++res;
            }
        }
        return res;
    }
};

//SECOND TRIAL
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!s)
            return 0;
        int end = strlen(s)-1, ans = 0;
        while(0<=end && *(s+end)==' ')
            --end;
        if(0>end)
            return 0;
        ans = end;
        while(end>=0 && isalpha(*(s+end)))
            --end;
        return ans-end;
    }
};
