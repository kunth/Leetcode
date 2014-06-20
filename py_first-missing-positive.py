class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        cnt = 0
        while cnt < len(A):
            if A[cnt] > 0 and A[cnt] <= len(A):
                if A[cnt] <= cnt + 1:
                    A[ A[cnt]-1 ] = A[cnt]
                    cnt += 1
                elif A[ A[cnt]-1 ] <=0 or A[ A[cnt]-1 ]>len(A):
                    A[ A[cnt]-1 ] = A[cnt]
                    cnt += 1
                elif A[cnt] != A[ A[cnt]-1 ]:
		    #better to use tmp to swap
                    #tmp = A[cnt]
                    #A[cnt] = A[A[cnt]-1]
                    #A[tmp-1] = tmp
		    #Attention!! this one is OK, but A[cnt], A[A[cnt]-1] = A[A[cnt]-1], A[cnt] is wrong
                    A[A[cnt]-1], A[cnt] = A[cnt], A[A[cnt]-1]
                else:
                    cnt += 1
            else:
                cnt += 1
        
        for i in range(0, len(A)):
            if A[i] != i+1:
                return i+1
        return len(A)+1
