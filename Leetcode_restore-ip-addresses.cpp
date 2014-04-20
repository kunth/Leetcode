class Solution {
private:
    stringstream ss;
    int num;
public:
    void dfs(vector<string>&ans, int cnt, string ipstr, string s)
    {
        if(cnt == 4 && s.empty())
        {
            ans.push_back(ipstr);
            return;
        }
        if(cnt)
            ipstr += '.';
        for(int i = 1; i<=3 && i<=s.length(); ++i)
        {
            ss.clear();
            ss.str("");
            ss << s.substr(0, i);
            ss >> num;
            switch(i)
            {
                case 2:
                    if(num<10)
                        continue;
                break;
                case 3:
                    if(num<100 || num>255)
                        continue;
                break;
                default:
                break;
            }
            ipstr += s.substr(0, i);
            dfs(ans, cnt+1, ipstr, s.substr(i));
            ipstr = ipstr.substr(0, ipstr.length()-i);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if(s.empty() || s.length()<4 || s.length()>12)
            return ans;
        dfs(ans, 0, "", s);
        return ans;
    }
};
