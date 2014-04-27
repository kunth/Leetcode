class Solution {
private:
    map<char, vector<char>>dm;
public:
    void dfs(vector<string>&ans, string str, string digits)
    {
        if(digits.empty())
        {
            ans.push_back(str);
            return;
        }
        char ch = digits[0];
        for(int i = 0; i < dm[ch].size(); ++i)
        {
            str += dm[ch][i];
            dfs(ans, str, digits.substr(1));
            str = str.substr(0, str.length()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty())
        {
            ans.push_back(digits);
            return ans;
        }
        int st = 0, ed = 0;
        dm.clear();
        for(char i = 2; i<=9; ++i)
        {
            if(i==7 || i==9)
                ed += 4;
            else
                ed += 3;
            for(int j = 0; j<ed-st; ++j)
                dm[i+'0'].push_back(st+'a'+j);
            st = ed;
        }
        dfs(ans, "", digits);
    }
};
