class Solution {
public:
    double pow(double x, int n) {
        if(!n)
            return 1.0;
        if(n<0)
        {
            if(n==-2147483648)
            {
                int m = n+1;
                return 1/(x*pow(x, -m));
            }
            return 1/pow(x, -n);
        }
        int cnt = 0;
        double ans = 1.0;
        if(fabs(fabs(x)-ans)<0.000001)
        {
            if(x<0 && !n%2)
                return -x;
            return x;
        }
        while(cnt < n)
        {
            int i = 1;
            double tmp = x;
            while(cnt+i+i<n && fabs(tmp)>0.000001)
            {
                i+=i;
                tmp *= tmp;
            }
            cnt += i;
            ans *= tmp;
            if(fabs(ans) < 0.000000001)
                return 0.0;
        }
        return ans;
    }
};

//Solution 2:
class Solution {
public:
    double pow(double x, int n) {
        if(abs(fabs(x)-1)<10e-8)
        {
            if(x<0)
            {
                if(n==-n)
                    return -x;
                return n%2 ? x : -x;
            }
            return x;
        }
        if(!x)
            return 0;
        if(n==0)
            return 1;
        bool f = true;
        if(n<0)
            f = (n = -n, false);
        if(n==1)
            return f ? x : 1/x;
        double ans = 1.0, tmp = x;
        int cnt = 1;
        while(n)
        {
            if(cnt+cnt<=n)
            {
                while(cnt + cnt <= n)
                {
                    cnt += cnt;
                    tmp *= tmp;
                    if(fabs(tmp)<10e-8)
                        return 0;
                }
                n -= cnt;
                ans *= tmp;
            }
            if(!n)
                return f ? ans : 1/ans;
            cnt = 1;
            ans *= x;
            --n;
            tmp = x;
        }
        return f ? ans : 1/ans;
    }
};

//The 2 above codes are too horrible to see it again.
//Here is the better code:

class Solution {
public:
    double pow(double x, int n) {
        double ans = 1;
        bool flag = true;
        if (n < 0) {
            flag = false;
            n = -n;
        }
        while (n) {
            if (n % 2 != 0) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
        if (flag) {
            return ans;
        }
        return 1.0 / ans;
    }
};

//Solution same with above
class Solution {
public:
    double pow(double x, int n) {
        bool f = true;
        if(n<0)
            f = (n = -n, false);
        double ans = 1.0;
        while(n)
        {
            if(n%2)
                ans *= x;
            x*=x;
            n/=2;
        }
        return f ? ans : 1/ans;
    }
};
