class Solution {
public:
    void dfs(vector<vector<string>>&ans, vector<int>vec, int n)
    {
        if(vec.size()==n)
        {
            vector<string>sv;
            for(int i = 0; i<n; ++i)
            {
                string str;
                str.clear();
                for(int j = 0; j<n; ++j)
                {
                    if(j==vec[i])
                        str+="Q";
                    else
                        str+=".";
                }
                sv.push_back(str);
            }
            ans.push_back(sv);
            return;
        }
        vector<string>v;
        if(vec.empty())
        {
            for(int i = 0; i<n; ++i)
            {
                vec.push_back(i);
                dfs(ans, vec, n);
                vec.pop_back();
            }
        }
        else 
        {
            vector<bool>flag(n, false);
            int num = vec.size(), diff;
            for(int i = 0; i<num; ++i)
            {
                diff = num - i;
                flag[vec[i]] = true;
                if(vec[i]-diff>=0)
                    flag[vec[i]-diff] = true;
                if(vec[i]+diff<=n-1)
                    flag[vec[i]+diff] = true;
            }
            for(int i = 0; i<n; ++i)
            {
                if(!flag[i])
                {
                    vec.push_back(i);
                    dfs(ans, vec, n);
                    vec.pop_back();
                }
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>>ans;
        if(n<=0)
            return ans;
        vector<int>vec;
        dfs(ans, vec, n);
        return ans;
    }
};
