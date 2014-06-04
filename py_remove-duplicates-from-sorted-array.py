class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if len(A) <= 1:
            return len(A)
        cnt = 1
        for i in range(1, len(A)):
            if A[i] != A[cnt-1]:
                A[cnt] = A[i]
                cnt += 1
        return cnt
