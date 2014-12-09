# Solution 1: O(n) time complexity
class Solution:
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        sz = len(num)
        if sz == 1:
            return 0
        for i in range(1, sz-1):
            if num[i] > num[i-1] and num[i] > num[i+1]:
                return i
        
        if num[0] > num[1]:
            return 0
        elif num[sz-1] > num[sz-2]:
            return sz-1

# Solution 2: O(logn) time complexity
class Solution:
    def findSubPeak(self, num, left, right):
        sz = len(num)
        if sz == 1:
            if num[0] > left and num[0] > right:
                return 0
            else:
                return -1
        elif sz == 2:
            if num[0] > left and num[0] > num[1]:
                return 0
            elif num[0] < num[1] and num[1] > right:
                return 1
            else:
                return -1
                
        mid = num[sz/2]
        lnum = num[:sz/2]
        rnum = num[sz/2+1:]
        x = self.findSubPeak(lnum, left, mid)
        if x != -1:
            return x
        elif mid > num[sz/2-1] and mid > num[sz/2+1]:
            return sz/2
        else:
            x = self.findSubPeak(rnum, mid, right)
            if x != -1:
                return x + 1 + sz/2
        return -1
    # @param num, a list of integer
    # @return an integer
    def findPeakElement(self, num):
        return self.findSubPeak(num, -2**32, -2**32)
