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
