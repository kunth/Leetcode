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

//SECOND TRIAL
class Solution {
private:
    int n, k;
    void dfs(vector<vector<int> >&ans, vector<int>&vec)
    {
        int left = k-(int)vec.size();
        if(left<=0)
        {
            ans.push_back(vec);
            return;
        }
        
        for(int i = 0; i<n; ++i)
        {
            if(i<=n-left && (vec.empty() || i+1>vec[vec.size()-1]))
            {
                vec.push_back(i+1);
                dfs(ans, vec);
                vec.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >ans;
        if(!n || !k || k>n)
            return ans;
        this->n = n;
        this->k = k;
        vector<int>vec;
        dfs(ans, vec);
        return ans;
    }
};
