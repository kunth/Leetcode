class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p=='\0')
            return *s=='\0';
        if(*(p+1)=='*')
        {
            while((*p=='.' && *s != '\0') || (*p==*s))
            {
                if(isMatch(s, p+2))
                    return true;
                ++s;
            }
            return isMatch(s, p+2);
        }
        else
        {
            if(*s==*p || (*p=='.' && *s!='\0'))
                return isMatch(s+1, p+1);
            return false;
        }
    }
};
