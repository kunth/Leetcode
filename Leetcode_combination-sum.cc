class Solution {
public:
    void dfs(vector<vector<int>>&ans, vector<int>tmpvec, vector<int> &candidates, int target)
    {
        if(target==0)
        {
            ans.push_back(tmpvec);
            return;
        }
        for(int i = 0; i<candidates.size(); ++i)
        {
            if(candidates[i]>target)
                break;
            if(tmpvec.empty() || candidates[i]>=tmpvec.back())
            {
                tmpvec.push_back(candidates[i]);
                dfs(ans, tmpvec, candidates, target-candidates[i]);
                tmpvec.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>>ans;
        if(candidates.empty())
            return ans;
        sort(candidates.begin(), candidates.end());
        vector<int>tmpvec;
        dfs(ans, tmpvec, candidates, target);
        return ans;
    }
};
