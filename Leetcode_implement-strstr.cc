class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!needle || !haystack || strlen(needle)>strlen(haystack))
            return NULL;

        for(int i = 0; i <= strlen(haystack) - strlen(needle); ++i)
        {
            bool flag = true;
            for(int j = 0; j < strlen(needle); ++j)
            {
                 if(needle[j] != haystack[i+j])
                 {
                     flag = false;
                     break;
                 }
            }
            if(flag)
                return haystack+i;
        }
        return NULL;
    }
};

//SECOND TRIAL
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len1 = strlen(haystack), len2 = strlen(needle);
        if(!haystack || !needle || len1 < len2)
            return NULL;
        for(int i = 0; i<= len1-len2; ++i)
        {
            int j = 0;
            for(; j<len2; ++j)
            {
                if(*(haystack+i+j) != *(needle+j))
                    break;
            }
            if(j==len2)
                return haystack+i;
        }
        return NULL;
    }
};
