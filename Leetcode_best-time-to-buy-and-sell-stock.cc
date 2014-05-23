class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
           
        int ret=-1, min_val=0x7fffffff;
        for(int i=0; i<prices.size(); ++i)
        {
            min_val = min(min_val, prices[i]);
            ret = max(ret, prices[i]-min_val);
        }
        return ret;
    }
};
