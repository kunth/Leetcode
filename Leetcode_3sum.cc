class Solution {
public:
     vector<vector<int> > threeSum(vector<int> &num) {
          vector<vector<int> > ans;
          sort(num.begin(), num.end());
          if(num.empty() || num.size() < 3 || num[0]>0 || num.back()<0)
               return ans;

          for(int i = 0; i < num.size()-2; ++i)
          {
               if(i>0 && num[i]==num[i-1])
                   continue;
               int left = i + 1, right = num.size()-1;
               while(left < right)
               {
                   if(right < num.size()-1 && num[right] == num[right+1])
                   {
                       --right;
                       continue;
                   }
                   if(num[left]+num[right]+num[i]==0)
                   {
                       vector<int>vec;
                       vec.push_back(num[i]);
                       vec.push_back(num[left]);
                       vec.push_back(num[right]);
                       ans.push_back(vec);
                       ++left;
                       --right;
                   }
                   else if(num[left]+num[right]+num[i]<0)
                       ++left;
                   else
                       --right;
               }
          }
          return ans;
     }
};

//SECOND TRIAL
//
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>>ans;
        sort(num.begin(), num.end());
        if(num.size()<3 || num.front()>0 || num.back()<0)
            return ans;
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
                    if(num[i]+num[k]+num[j]==0)
                    {
                        vector<int>tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[k]);
                        tmp.push_back(num[j]);
                        ans.push_back(tmp);
                        break;
                    }
                    else if(num[i]+num[k]+num[j]>0)
                        break;
                }
            }
        }
        return ans;
    }
};
