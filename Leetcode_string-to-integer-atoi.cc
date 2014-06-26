class Solution {
public:
    int atoi(const char *str) {
        if(!str)
            return 0;
            
        queue<int>q;
        int len = strlen(str), i = 0, num = 0;
        long long res = 0;
        bool flag = true;
        while(str[i]==' ')
        {
            ++i;
        }
        if(str[i]=='-')
        {
            ++i;
            flag = false;
        }
        else if(str[i]=='+')
        {
            ++i;
            flag = true;
        }
        else
            flag = true;
        
        for(; i < len; ++i)
        {
            num = str[i] - '0';
            if(num<0 || num >9)
            {
                break;
            }
            q.push(num);
        }
        while(!q.empty())
        {
            res = 10*res + q.front();
            q.pop();
        }
        if(flag && res > 2147483647)
           res = 2147483647;
        else if(!flag && res > 2147483648)
            res = 2147483648;
        return (int)(flag ? res : -res);
    }
};
