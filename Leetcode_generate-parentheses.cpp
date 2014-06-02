class Solution {
public:
    int g_n;
    void dfs(vector<string>&vec, string str, int left)
    {
        if(left==0)
        {
            for(int i = str.length(); i<2*g_n; ++i)
                str+=')';
            vec.push_back(str);
            return;
        }
        if(str.length()<2*(g_n-left))
        {
            str+=')';
            dfs(vec, str, left);
            str = str.substr(0, str.length()-1);
        }
        str+='(';
        dfs(vec, str, left-1);
    }
    vector<string> generateParenthesis(int n) {
      vector<string>vec;
      if(n<=0)
          return vec;
      string str;
      this->g_n = n;
      dfs(vec, str, n);
      return vec;
    }
};

//SECOND TRIAL
class Solution {
private:
    int n;
    void dfs(vector<string>&ans, string str, int left, int diff)
    {
        if(left == n && !diff)
        {
            ans.push_back(str);
            return;
        }
        if(left<n)
        {
            str += '(';
            dfs(ans, str, left+1, diff+1);
            if(diff>0)
            {
                str[str.length()-1]=')';
                dfs(ans, str, left, diff-1);
            }
        }
        else
        {
            str += ')';
            dfs(ans, str, left, diff-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        vector<string>ans;
        string str;
        dfs(ans, "", 0, 0);
        return ans;
    }
};
