class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        k = i = 0
        j = len(A)-1
        while k<=j:
            if not A[k]:
                A[i], A[k] = A[k], A[i]
                i+=1
            elif A[k]==2:
                A[j], A[k] = A[k], A[j]
                j-=1
            else:
                k+=1
            if i>k:
                k = i
