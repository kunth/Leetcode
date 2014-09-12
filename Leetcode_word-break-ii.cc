class Solution {
public:
    void dfs(vector<string>&res, string tmpstr, map<char, vector<string>>&dm, string s)
    {
        if(s.empty())
        {
            res.push_back(tmpstr);
            return;
        }
        auto it = dm.find(s[0]);
        if(it == dm.end())
            return;
        int len;
        string copystr;
        for(auto str_it = it->second.begin(); str_it != it->second.end(); ++str_it)
        {
            len = (*str_it).length();
            copystr = tmpstr;
            if(len<=s.length() && *str_it==s.substr(0,len))
            {
                if(copystr.empty())
                    copystr+=*str_it;
                else
                {
                    copystr+=' ';
                    copystr+=*str_it;
                }
                dfs(res, copystr, dm, s.substr(len));
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string>res;
        if(dict.empty() || s.empty())
            return res;
        vector<bool>dp(s.length()+1, false);
        dp[0]=true;
        for(int i = 0; i<s.length(); ++i)
        {
            for(int j = 1; i+j<=s.length(); ++j)
            {
                if(dp[i] && dict.find(s.substr(i,j)) != dict.end())
                    dp[i+j] = true;
            }
        }
        if(!dp[s.length()])
            return res;
        map<char, vector<string>>dm;
        for(auto it = dict.begin(); it!=dict.end(); ++it)
            dm[(*it)[0]].push_back(*it);
        dfs(res, "", dm, s);
        return res;
    }
};

//Second trial, which is the same thought, but simplifies the code
class Solution {
private:
    void dfs(vector<string>&ans, vector<string>&vec, string s, unordered_set<string> &dict) {
        if(s.empty()) {
            string str = vec[0];
            for(int i = 1; i<vec.size(); ++i) {
                str += " ";
                str += vec[i];
            }
            ans.push_back(str);
        }
        string word;
        for(int i = 1; i<=s.length(); ++i) {
            word = s.substr(0, i);
            if(dict.find(word)!=dict.end()) {
                vec.push_back(word);
                dfs(ans, vec, s.substr(i), dict);
                vec.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string>ans, vec;
        if(s.empty() || dict.empty())
            return ans;
        vector<bool>dp(s.length()+1, false);
        dp[0] = true;
        int len;
        for(int i = 0; i<s.length(); ++i){
            for(auto it = dict.begin(); it != dict.end(); ++it) {
                len = (*it).length();
                if(dp[i] && i+len<=s.length() && s.substr(i, len)==*it)
                    dp[i+len] = true;
            }
            if(dp[s.length()])
                break;
        }
        if(dp[s.length()])
            dfs(ans, vec, s, dict);
        return ans;
    }
};
