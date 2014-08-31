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

//Second trial, almost the same
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string>ans;
        if(strs.size()<=1)
            return ans;
        map<string, vector<string> >M;
        string word;
        vector<string> vec;
        for(int i = 0; i<strs.size(); ++i) {
            word = strs[i];
            sort(word.begin(), word.end());
            if(M[word].empty()) {
            }
            M[word].push_back(strs[i]);
        }
        for(auto it = M.begin(); it != M.end(); ++it) {
            if(it->second.size() > 1)
                ans.insert(ans.end(), it->second.begin(), it->second.end());
        }
        return ans;
    }
};
