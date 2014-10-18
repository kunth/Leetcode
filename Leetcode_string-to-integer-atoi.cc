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

//ANOTHER SOLUTION
class Solution {
public:
    int atoi(const char *str) {
        if(!str || !strlen(str))
            return 0;
        while(*str==' ')
            ++str;
        bool isPositive = true;
        if(*str=='-') {
            isPositive = false;
            ++str;
        }
        else if(*str=='+') {
            ++str;
        }
        long long int ans = 0;
        while(*str) {
            if(*str<'0' || *str>'9')
                break;
            ans = ans*10 + *str - '0';
            ++str;
        }
        if(isPositive) {
            if(ans > INT_MAX)
                return INT_MAX;
            return ans;
        } else {
            if(ans-1 >= INT_MAX)
                return INT_MIN;
            else
                return -ans;
        }
    }
};
