class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *copyp = NULL, *copys = s;
        while(*s)
        {
            if(*s==*p || *p=='?')
            {
                ++s;
                ++p;
            }
            else if(*p=='*')
            {
                copyp = p++;
                copys = s;
            }
            else if(copyp)
            {
                p = copyp+1;
                s = ++copys;
            }
            else
                return false;
        }
        while(*p && *p=='*')
            ++p;
        return !(*p);
    }
};
