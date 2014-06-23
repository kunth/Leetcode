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

//SECOND TRIAL
class Solution {
private:
    void dfs(vector<string>&ans, string dst, string src, int cnt)
    {

        if(cnt>=4)
        {
            if(cnt==4 && src.empty())
                ans.push_back(dst);
            return;
        }
        for(int i = 1; i<=3; ++i)
        {
            if(src.length()>=i)
            {
                if(i == 2 && src[0]=='0')
                    continue;
                else if(i == 3)
                {
                    int num;
                    string tmp = src.substr(0, 3);
                    stringstream ss;
                    ss << tmp;
                    ss >> num;
                    if(num>255 || num<100)
                        continue;
                }
                if(cnt)
                    dst+=".";
                dst+=src.substr(0, i);
                dfs(ans, dst, src.substr(i), cnt+1);
                if(cnt)
                    dst = dst.substr(0, dst.length()-i-1);
                else
                    dst = dst.substr(0, dst.length()-i);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if(s.length()<4 || s.length()>12)
            return ans;
        dfs(ans, "", s, 0);
        return ans;
    }
};
