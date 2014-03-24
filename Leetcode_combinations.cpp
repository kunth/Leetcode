class Solution {
public:
    int g_n;
    vector<vector<int> > res;
    vector<int> tmp;
    
    void dfs(int begin, int left)
    {
        if(!left)
        {
            res.push_back(tmp);
            return;
        }
        for(int i = begin; i <= g_n - left + 1; ++i)
        {
            tmp.push_back(i);
            dfs(i+1, left-1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        res.clear();
        tmp.clear();
        if(n >= k)
        {
           this->g_n = n;
           dfs(1, k);
        }
        return res;
    }
};
