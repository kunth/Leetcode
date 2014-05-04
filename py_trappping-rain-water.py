class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        if not A or len(A)<=2:return 0
        mid = max(A)
        mid_idx = A.index(mid)
        area=0
        if A[:mid_idx]:
            left = max(A[:mid_idx])
            left_idx = A.index(left)
            for i in range(left_idx, mid_idx):
                area += A[left_idx] - A[i]
            area += self.trap(A[:left_idx+1])

        if A[mid_idx+1:]:
            right = max(A[mid_idx+1:])
            for i in range(mid_idx+1, len(A)):
                if A[i] == right:
                    right_idx = i
                    break;
            for i in range(mid_idx+1, right_idx):
                area += A[right_idx] - A[i]
            area += self.trap(A[right_idx:])
            
        return area
