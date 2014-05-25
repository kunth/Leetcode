class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, vector<int>> dm;
        vector<int>res;
        for(int i = 0; i < numbers.size(); ++i)
        {
            dm[numbers[i]].push_back(i);
            if(!dm[target-numbers[i]].empty())
            {
                if(numbers[i]==target-numbers[i]&&dm[numbers[i]].size()>=2)
                {
                    res.push_back(dm[numbers[i]][0]+1);
                    res.push_back(dm[numbers[i]][1]+1);
                    return res;
                }
                else if(i<dm[target-numbers[i]][0])
                {
                    res.push_back(i+1);
                    res.push_back(dm[target-numbers[i]][0]+1);
                    return res;
                }
                else if(i>dm[target-numbers[i]][0])
                {
                    res.push_back(dm[target-numbers[i]][0]+1);
                    res.push_back(i+1);
                    return res;
                }
            }
        }
    }
};


//second trial
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        if(numbers.empty())
            return ans;
        unordered_map<int, int>mp;
        for(int i = 0; i<numbers.size(); ++i)
        {
            auto it = mp.find(target-numbers[i]);
            if(it!=mp.end())
            {
                ans.push_back(it->second+1);
                ans.push_back(i+1);
                return ans;
            }
            else
                mp[numbers[i]] = i;
        }
    }
};
