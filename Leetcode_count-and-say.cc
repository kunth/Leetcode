class Solution {
public:
    string countAndSay(int n) {
        string str;
        if(!n)
            return str;
        str = "1";
        int len, cnt;
        char ch;
        queue<string>q;
        for(int i = 1; i<n; ++i)
        {
            len = str.length();
            cnt = 0;
            ch = str[0];
            for(int j = 0; j<len; ++j)
            {
                if(str[j]==ch)
                    ++cnt;
                else
                {
                    string tmp;
                    tmp += char(cnt+'0');
                    tmp += ch;
                    q.push(tmp);
                    cnt = 1;
                    ch = str[j];
                }
            }
            string tmp;
            tmp += char(cnt+'0');
            tmp += ch;
            q.push(tmp);
            tmp.clear();
            while(!q.empty())
            {
                tmp+=q.front();
                q.pop();
            }
            str = tmp;
        }
        return str;
    }
};
