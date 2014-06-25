class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        if not A:
            return False
        if len(A)==1:
            return True;
        far = 0
        for i in range(0, len(A)):
            if i<=far:
                far = max(far, i+A[i])
                if far >= len(A)-1:
                    return True
            else:
                return False
        return False
