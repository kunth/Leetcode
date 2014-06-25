class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        ans = A[0]
        s = 0
        for i in range(0, len(A)):
            s += A[i]
            ans = max(s, ans)
            if s < 0:
                s = 0
        return ans
