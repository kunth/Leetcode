class Solution:
    # @return a string
    def getPermutation(self, n, k):
        arr = range(1, n+1)
        ans = ""
        while arr:
            cur = (k-1) // math.factorial(n-1)
            ans += str(arr[cur])
            k %= math.factorial(n-1)
            n -= 1
            arr.pop(cur)
        return ans
