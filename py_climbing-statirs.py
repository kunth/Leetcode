class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        if n<=0:
            return 0;
        array = [1, 1, 2]
        while len(array) <= n:
            array.append(array[-1] + array[-2])
        return array[n]
