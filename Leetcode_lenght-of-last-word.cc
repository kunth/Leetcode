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
