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
