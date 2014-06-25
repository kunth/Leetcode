class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if not n: return 1
        if n == 1: return x
        flag = True
        if n < 0:
            flag = False
            n = -n
        ans = 1.0
        cnt = 1
        while n:
            if n & 0x1:
                ans *= x
            x *= x
            n /= 2
        if flag:
            return ans
        else:
            return 1.0 / ans


#This one is also accepted, but worse than the last one, although it may be easier understanding.

"""
class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        if not n: return 1
        if n == 1: return x
        flag = True
        if n < 0:
            flag = False
            n = -n
        ans = 1.0
        cnt = 0
        while cnt < n:
            tmpow = 1
            tmpans = x
            while cnt+tmpow*2 <= n:
                tmpow *= 2
                tmpans *= tmpans
            cnt += tmpow
            ans *= tmpans
        if flag:
            return ans
        else:
            return 1.0 / ans
"""
