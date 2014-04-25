class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int min_val = 1<<30, ans = 0;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size()-2; ++i)
        {
            if(i && num[i]==num[i-1])
                continue;
            int left = i + 1, right = num.size() - 1;
            while(left < right)
            {
                if(right<num.size()-2 && num[right]==num[right+1])
                {
                    --right;
                    continue;
                }
                if(num[i]+num[left]+num[right]==target)
                    return target;
                else if (num[i]+num[left]+num[right]>target)
                {
                    if(min_val > num[i]+num[left]+num[right] - target)
                    {
                        ans = num[i]+num[left]+num[right];
                        min_val = num[i]+num[left]+num[right] - target;
                    }
                    --right;
                }
                else
                {
                    if(min_val > target - (num[i]+num[left]+num[right]))
                    {
                        ans = num[i]+num[left]+num[right];
                        min_val = target-(num[i]+num[left]+num[right]);
                    }
                    ++left;
                }
            }
        }
        return ans;
    }
};
