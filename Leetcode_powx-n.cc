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

//Sorry, the last code is too horrible to see it again.
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
