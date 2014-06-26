class Solution:
    # @return a list of integers
    def grayCode(self, n):
        n = 1 << n
        ans = []
        for i in range(0, n):
            ans.append(i ^ i//2)
        return ans
