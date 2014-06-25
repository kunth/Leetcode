class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        if not dividend : return dividend
        p = True
        if dividend<0 and divisor>0 or dividend>0 and divisor<0: p = False
        if dividend < 0 : dividend = -dividend
        if divisor < 0 : divisor = -divisor
        if dividend < divisor:
            return 0
        else:
            ans = 0
            while divisor <= dividend:
                cnt = 1
                s = divisor
                while s*2 <= dividend:
                    cnt*=2
                    s*=2
                ans += cnt
                dividend -= s
            if p : return ans
            else : return -ans
