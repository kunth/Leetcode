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

//SECOND TRIAL, 60ms
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1)
            return 0;
        vector<int>v1(prices.size(), 0), v2(prices.size(), 0);
        int low = prices[0], high = prices[prices.size()-1];
        for(int i = 1; i<prices.size(); ++i)
        {
            low = min(low, prices[i]);
            v1[i] = max(v1[i-1], prices[i] - low);
        }
            
        for(int j = prices.size()-2; j>=0; --j)
        {
            high = max(high, prices[j]);
            v2[j] = max(v2[j+1], high - prices[j]);
        }
        int ans = 0;
        for(int i = 0; i<prices.size(); ++i)
            ans = max(ans, v1[i]+v2[i]);
        return ans;
    }
};
