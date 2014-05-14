class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1)
            return 0;
        int buy_low = INT_MAX, sell_high = INT_MIN, profit = 0, ans = 0;
        vector<int>first_profit(prices.size(), 0);
        for(int i = 0; i<prices.size(); ++i)
        {
            if(prices[i]<buy_low)
                buy_low = prices[i];
            else
                profit = max(profit, prices[i]-buy_low);
            first_profit[i] = profit;
        }
        profit = 0;
        for(int i = prices.size()-1; i>=0; --i)
        {
            if(prices[i]>sell_high)
                sell_high = prices[i];
            else
                profit = max(profit, sell_high - prices[i]);
            ans = max(ans, first_profit[i] + profit);
        }
        return ans;
    }
};
