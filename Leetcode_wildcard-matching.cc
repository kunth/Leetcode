class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(!s && !p)
            return true;
        const char *cs = NULL, *cp = NULL;
        while(*s) {
            if(*s==*p || *p == '?'){
                ++s;
                ++p;
            } else if(*p=='*') {
                cp = p++;
                cs = s;
            } else if(cp) {
                p = cp+1;
                s = ++cs;
            } else
                return false;
        }
        while(*p && *p=='*')
            ++p;
        return !(*p);
    }
};
