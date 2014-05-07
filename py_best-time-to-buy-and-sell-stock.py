class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if not prices:
            return 0
        cur_min = prices[0]
        m = 0
        for i in prices:
            m = max(m, i-cur_min)
            cur_min = min(cur_min, i)
        return m
