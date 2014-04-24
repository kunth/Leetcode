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
