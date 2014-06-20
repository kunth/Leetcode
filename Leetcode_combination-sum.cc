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

//SECOND TRIAL, almost the same
class Solution {
private:
    vector<int>candidates;
    vector<vector<int> >ans;
    void dfs(vector<int>&vec, int left)
    {
        if(!left)
        {
            ans.push_back(vec);
            return;
        }
        for(int i = 0; i<candidates.size(); ++i)
        {
            if(left-candidates[i]>=0)
            {
                if(vec.empty() || candidates[i]>=vec.back())
                {
                    vec.push_back(candidates[i]);
                    dfs(vec, left-candidates[i]);
                    vec.pop_back();
                }
            }
            else
                break;
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if(candidates.empty())
            return this->ans;
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        vector<int>vec;
        dfs(vec, target);
        return this->ans;
    }
};
