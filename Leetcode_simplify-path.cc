class Solution {
public:
    string simplifyPath(string path) {
        vector<string>vec;
        string ans, dir;
        for(int i = 0; i < path.length(); )
        {
            int j = i;
            while(j < path.length() && path[j]!='/')
                ++j;
            dir = path.substr(i, j-i);
            if(!dir.empty())
            {
                if(dir=="..")
                {
                    if(!vec.empty())
                        vec.pop_back();
                }
                else if(dir!=".")
                    vec.push_back(dir);
            }
            i = j + 1;
        }
        if(vec.empty())
            return "/";
        else
        {
           
            for(int i = 0; i<vec.size(); ++i)
            {
                ans += '/';
                ans += vec[i];
            }
        }
        return ans;
    }
};
