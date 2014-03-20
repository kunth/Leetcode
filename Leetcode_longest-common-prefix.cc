class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
        bool flag = true;
        int i;
        if(strs.empty())
        return ret;
        for(i=0; i<strs[0].length() && flag; ++i)
        {
            char ch = strs[0].at(i);
            for(int j = 1; j<strs.size(); ++j)
            {
                if(i == strs[j].length())
                {
                    flag = false;
                    break;
                }
                    
               if(strs[j].at(i) != ch)
               {
                  flag = false;
                  break;
               }
            }
        }
        if(flag == true)
        {
            ret = strs[0].substr(0,i);
        }
        else if(i>0)
        {
            ret = strs[0].substr(0,i-1);
        }
        return ret;
    }
};
