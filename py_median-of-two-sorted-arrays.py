class Solution:
    # @return a float
    def find_kth_num(self, A, m, B, n, k):
        if m > n:
            return self.find_kth_num(B, n, A, m, k)
        if not A:
            return float(B[k-1])
        if k == 1:
            return float(min(A[0], B[0]))
        idx_a = min(m, k//2)
        idx_b = k - idx_a
        if A[idx_a-1] < B[idx_b-1]:
            return self.find_kth_num(A[idx_a:], m-idx_a, B, n, k-idx_a)
        elif A[idx_a-1] > B[idx_b-1]:
            return self.find_kth_num(A, m, B[idx_b:], n-idx_b, k-idx_b)
        else:
            return float(A[idx_a-1])
            
    def findMedianSortedArrays(self, A, B):
        if (len(A)+len(B)) & 0x1:
            return self.find_kth_num(A, len(A), B, len(B), (len(A)+len(B)+1)//2)
        else:
            return (self.find_kth_num(A, len(A), B, len(B), (len(A)+len(B))//2) + self.find_kth_num(A, len(A), B, len(B), (len(A)+len(B))//2 + 1)) / 2.0
