class Solution:
    # @param A a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if len(A)<=2:
            return len(A)
        cnt = 1
        flag = True
        for i in range(1, len(A)):
            if A[i] != A[i-1]:
                flag = True
                A[cnt] = A[i]
                cnt += 1
            elif flag:
                flag = False
                A[cnt] = A[i]
                cnt += 1
        return cnt
