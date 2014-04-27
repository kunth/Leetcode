class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        ans = 0;
        for i in A:
            ans ^= i
        return ans
