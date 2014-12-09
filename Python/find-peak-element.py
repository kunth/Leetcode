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
