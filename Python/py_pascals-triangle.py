class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        if numRows <= 0:
            return []
        ans = []
        for i in range(0, numRows):
            vec = [1] * (i+1)
            for j in range(0, i+1):
                if j > 0 and j < i:
                    vec[j] = ans[i-1][j-1] + ans[i-1][j]
            ans.append(vec)
        return ans
