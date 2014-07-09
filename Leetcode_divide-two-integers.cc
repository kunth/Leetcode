class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_pos = true;
        long long int sor = divisor, end = dividend, tmp = divisor;
        if(end>0 && sor<0)
        {
            is_pos = false;
            sor = -sor;
        }
        else if(end<0 && sor>0)
        {
            is_pos = false;
            end = -end;
        }
        else if(end<0 && sor<0)
        {
            end = -end;
            sor = -sor;
        }
        if(!end || end<sor)
            return 0;
        int ans = 0, sum = 1;
        while(sor <= end)
        {
            sum = 1;
            tmp = sor;
            while(tmp + tmp <= end)
            {
                sum += sum;
                tmp += tmp;
            }
            end -= tmp;
            ans += sum;
        }
        return is_pos ? ans : -ans;
    }
};
