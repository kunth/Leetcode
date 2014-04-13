class Solution {
public:
    void dfs(int&ans, vector<int>vec, int n)
    {
        if(vec.size()==n)
        {
            ++ans;
            return;
        }
        if(vec.empty())
        {
            for(int i = 0; i<n; ++i)
            {
                vec.push_back(i);
                dfs(ans, vec, n);
                vec.pop_back();
            }
            return;
        }
        int num = vec.size(), diff = 0;
        vector<bool>flag(n, false);
        for(int i = 0; i<num; ++i)
        {
            diff = num - i;
            flag[vec[i]] = true;
            if(vec[i]-diff>=0)
                flag[vec[i]-diff] = true;
            if(vec[i]+diff<n)
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
    int totalNQueens(int n) {
        if(n<=0)
            return 0;
        int ans = 0;
        vector<int>vec;
        dfs(ans, vec, n);
        return ans;
    }
};
