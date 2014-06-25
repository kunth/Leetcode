#Attention for python's list assignment
#use a = b[:] instead of a = b
class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        v1 = [1]*rowIndex 
        v2 = [1]*(rowIndex+1)
        if rowIndex<=1:
            return v2
        for i in range(2, rowIndex+1):
            for j in range(1, i):
                v2[j] = v1[j-1] + v1[j]
            v1 = v2[:-1]
        return v2
