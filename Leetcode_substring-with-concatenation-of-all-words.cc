//AC

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int>ans;
        if(S.empty() || L.empty())
            return ans;
        int one_word_len = L[0].length();
        map<string, int>dm, tmpm;
        for(int i = 0; i<L.size(); ++i)
            dm[L[i]] = dm[L[i]]==0 ? 1 : dm[L[i]]+1;
        
        for(int i = 0; i + one_word_len*L.size() <= S.length(); ++i)
        {
            int j = 0;
            tmpm.clear();
            for(; j < L.size(); ++j)
            {
                string str = S.substr(i+j*one_word_len, one_word_len);
                if(dm.find(str)!=dm.end() && tmpm[str]<dm[str])
                {
                    ++tmpm[str];
                }
                else
                {
                    break;
                }
            }
            if(j==L.size())
                ans.push_back(i);
        }
        return ans;
    }
};

//TLE

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int>ans;
        if(S.empty() || L.empty())
            return ans;
        int one_word_len = L[0].length();
        map<string, int>dm, backup;
        for(int i = 0; i<L.size(); ++i)
            dm[L[i]] = dm[L[i]]==0 ? 1 : dm[L[i]]+1;
        backup = dm;
        for(int i = 0; i + one_word_len*L.size() <= S.length(); ++i)
        {
            int j = 0;
            for(; j < L.size(); ++j)
            {
                string str = S.substr(i+j*one_word_len, one_word_len);
                if(dm.find(str)!=dm.end() && dm[str])
                {
                    --dm[str];
                }
                else
                {
                    dm = backup;
                    break;
                }
            }
            if(j==L.size())
                ans.push_back(i);
        }
        return ans;
    }
};
