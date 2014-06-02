class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>>ans;
        if(num.size()<4)
            return ans;
        sort(num.begin(), num.end());
        vector<int>vec(4, 0);
        for(int i = 0; i<(int)num.size()-3; ++i)
        {
            //if(i && num[i]==num[i-1])
            //    continue;
            int m = i + 3;
            for(;m<num.size(); ++m)
            {
                //if(m > i+3 && num[m]==num[m-1])
                //    continue;
                int j = i + 1, k = m-1;
                for(; j < k;)
                {
                    if(j > i + 1 && num[j]==num[j-1] )
                    {
                        ++j;
                        continue;
                    }
                    if(k < m-1 && num[k]==num[k+1])
                    {
                        --k;
                        continue;
                    }
                    if(num[i]+num[j]+num[k]+num[m]<target)
                        ++j;
                    else if(num[i]+num[j]+num[k]+num[m]>target)
                        --k;
                    else
                    {
                        vec[0] = num[i];
                        vec[1] = num[j];
                        vec[2] = num[k];
                        vec[3] = num[m];
                        if(find(ans.begin(), ans.end(), vec)==ans.end())
                            ans.push_back(vec);
                        --k;
                        ++j;
                    }
                }

            }
        }
        return ans;
    }
};


//SECOND TRIAL
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>>ans;
        if(num.size()<4)
            return ans;
        sort(num.begin(), num.end());
        int left = 0, right = 0;
        vector<int>vec(4, 0);
        for(int i = 0; i < num.size()-3; ++i)
        {
            if(i && num[i]==num[i-1])
                continue;
            for(int j = num.size()-1; j > i+2; --j)
            {
                if(j < num.size()-1 && num[j]==num[j+1])
                    continue;
                left = i + 1;
                right = j - 1;
                while(left < right)
                {   
                    if(left > i+1 && num[left]==num[left-1])
                        ++left;
                    else if(right < j-1 && num[right]==num[right+1])
                        --right;
                    else if(num[i]+num[j]+num[left]+num[right]==target)
                    {
                        vec[0] = num[i];
                        vec[1] = num[left];
                        vec[2] = num[right];
                        vec[3] = num[j];
                        ans.push_back(vec);
                        ++left;
                        --right;
                    }
                    else if(num[i]+num[left]+num[right]+num[j]<target)
                        ++left;
                    else if(num[i]+num[left]+num[right]+num[j]>target)
                        --right;
                }
            }
        }
        return ans;
    }
};
