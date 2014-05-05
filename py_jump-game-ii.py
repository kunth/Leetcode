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
