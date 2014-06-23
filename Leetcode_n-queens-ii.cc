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

//SECOND TRIAL
class Solution {
private:
    unordered_map<int, bool>addmp, minusmp;
    string str;
    int n;
    void dfs(int&ans, vector<string>&vec, vector<bool>&vrow, vector<bool>&vcol, int begin)
    {
        if(begin==n && vec.size()==n)
        {
            ++ans;
            return;
        }
        for(int j = 0; j<n; ++j)
        {
            if(!vrow[begin] && !vcol[j] && !addmp[begin+j] && !minusmp[begin-j])
            {
                vrow[begin] = vcol[j] = addmp[begin+j] = minusmp[begin-j] = true;
                string s = str;
                s[j] = 'Q';
                vec.push_back(s);
                dfs(ans, vec, vrow, vcol, begin+1);
                vec.pop_back();
                vrow[begin] = vcol[j] = addmp[begin+j] = minusmp[begin-j] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        int ans = 0;
        if(n<1)
            return 0;
        addmp.clear();
        minusmp.clear();
        this->n = n;
        for(int i = 0; i<n; ++i)
            str += '.';
        vector<bool>vrow(n, false), vcol(n, false);
        vector<string>vec;
        dfs(ans, vec, vrow, vcol, 0);
        return ans;
    }
};
