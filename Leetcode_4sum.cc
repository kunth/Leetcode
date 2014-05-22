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
