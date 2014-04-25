class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string>ans;
        map<string, vector<string> >dm;
        string idx;
        if(!strs.empty())
        {
            for(int i = 0; i<strs.size(); ++i)
            {
                idx = strs[i];
                sort(idx.begin(), idx.end());
                dm[idx].push_back(strs[i]);
            }
            for(auto it = dm.begin(); it != dm.end(); it++)
            {
                if(it->second.size()>1)
                {
                    ans.insert(ans.end(), it->second.begin(), it->second.end());
                }
            }
        }
        return ans;
    }
};
