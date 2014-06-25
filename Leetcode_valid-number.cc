class Solution {
public:
    bool isNumber(const char *s) {
        if(!s)
            return false;
        while(s && *s == ' ')
            ++s;
        int len = strlen(s);
        if(!len)
            return false;
        const char *end = s+len-1;
        while(end>s && *end--==' ')
            --len;
        if(*s=='-' || *s=='+')
        {
            --len;
            ++s;
        }
        int pos_e = -1, pos_dot = -1, pos_plus=-1, pos_minus=-1;
        bool has_num = false;
        for(int i = 0; i<len; ++i)
        {
            if(*(s+i)>='0' && *(s+i)<='9')
                has_num = true;
            else if(*(s+i)=='.')
            {
                if(pos_dot>=0)
                    return false;
                pos_dot = i;
                if(pos_e>=0)
                    return false;
            }
            else if(*(s+i)=='e')
            {
                if(pos_e>=0 || i==0 || i==len-1)
                    return false;
                pos_e = i;
                if(pos_dot>=0 && pos_dot+1==pos_e && (i==len-1 || pos_dot==0))
                    return false;
            }
            else if(*(s+i)=='+')
            {
                if(pos_plus>=0)
                    return false;
                pos_plus = i;
                if(pos_e==-1 || pos_plus>pos_e+1 || i==len-1)
                    return false;
            }
            else if(*(s+i)=='-')
            {
                if(pos_minus>=0)
                    return false;
                pos_minus = i;
                if(pos_e==-1 || pos_minus>pos_e+1 || i==len-1)
                    return false;
            }
            else
                return false;
        }
        return has_num;
    }
};
