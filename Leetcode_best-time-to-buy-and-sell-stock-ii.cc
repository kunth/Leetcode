class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        int res = 0, low, high;
        for(int i = 0; i < prices.size()-1; ++i)
        {
            if(prices[i]<prices[i+1])
            {
                low = prices[i];
                while(i+2<prices.size() && prices[i+1]<=prices[i+2])
                    ++i;
                high = prices[i+1];
                res += high-low;
                ++i;
            }
        }
        return res;
    }
};
