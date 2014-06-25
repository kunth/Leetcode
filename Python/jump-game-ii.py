class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        if not A or len(A)==1 : return 0
        ans = cur = farthest = 0
        while cur <= farthest:
            ans += 1
            nxt = farthest + 1
            for i in range(cur, nxt):
                if i+A[i]>farthest:
                    farthest = i + A[i]
                    if farthest >= len(A)-1:
                        return ans
            cur = nxt

#SECOND TRAIL
class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        if len(A)==1:
            return 0
        if A[0]>=len(A)-1:
            return 1
        begin = 0
        end = A[0]
        step = 0
        ans = 1
        while 2:
            while begin<=end:
                step = max(step, A[begin]+begin)
                begin += 1
            if step>=len(A)-1:
                return 1+ans
            begin = end
            end = step
            ans += 1
            step = 0
