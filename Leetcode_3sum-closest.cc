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

//SECOND TRIAL
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int diff = INT_MAX, ans = 0;
        sort(num.begin(), num.end());
        for(int i = 0; i<num.size()-2; ++i)
        {
            if(i && num[i]==num[i-1])
                continue;
            for(int j = num.size()-1; j>i+1; --j)
            {
                if(j < num.size()-1 && num[j]==num[j+1])
                    continue;
                for(int k = i + 1; k < j; ++k)
                {
                    if(k>i+1 && num[k]==num[k-1])
                        continue;
                    if(abs(num[i]+num[j]+num[k]-target)<diff)
                    {
                        diff = abs(num[i]+num[j]+num[k]-target);
                        ans = num[i]+num[j]+num[k];
                        if(!diff)
                            return target;
                    }
                }
            }
        }
        return ans;
    }
};

