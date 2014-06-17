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

//SECOND TRIAL, almost the same
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1)
            return 0;
        int ans = 0, pre_min = prices[0];
        for(int i = 1; i<prices.size(); ++i)
        {
            pre_min = min(pre_min, prices[i]);
            ans = max(ans, prices[i]-pre_min);
        }
        return ans;
    }
};
