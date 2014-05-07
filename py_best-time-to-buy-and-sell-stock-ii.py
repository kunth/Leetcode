class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if not prices or len(prices)==1: return 0
        ans = 0
        begin = prices[0]
        for i in range(1, len(prices)-1):
            if begin > prices[i]:
                begin = prices[i]
            if prices[i] > prices[i+1]:
                ans += prices[i] - begin
                begin = prices[i+1]
        if prices[-1] > begin:
            ans+=prices[-1] - begin;
        return ans
