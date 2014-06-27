class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        if not B or not n:
            return;
        if not A:
            A = B[:]
        la = m-1
        lb = n-1
        while la>=0 and lb>=0:
            if A[la]>=B[lb]:
                A[la+lb+1] = A[la]
                la -= 1
            else:
                A[la+lb+1] = B[lb]
                lb -= 1
        if la<0:
            while lb>=0:
                A[lb]=B[lb]
                lb -= 1
