class Solution {
public:
    void dfs(vector<vector<int>>&ans, vector<int>&num, vector<int>&visited, vector<int>tmpvec, int start, int target)
    {
        if(target==0)
        {
            if(find(ans.begin(), ans.end(), tmpvec)==ans.end())
                ans.push_back(tmpvec);
            return;
        }
        if(start>=num.size())
            return;
        if(!visited[start] && target-num[start]>=0)
        {
            visited[start] = true;
            tmpvec.push_back(num[start]);
            dfs(ans, num, visited, tmpvec, start+1, target-num[start]);
            tmpvec.pop_back();
            visited[start] = false;
            dfs(ans, num, visited, tmpvec, start+1, target);
        }
        
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>>ans;
        if(num.empty())
            return ans;
        sort(num.begin(), num.end());
        vector<int>visited(num.size(), 0), tmpvec;
        dfs(ans, num, visited, tmpvec, 0, target);
        return ans;
    }
};

//SECOND TRIAL
class Solution {
private:
    vector<vector<int> >ans;
    vector<int>num;
    void dfs(vector<int>&vec, vector<bool>&visited, int left)
    {
        if(!left)
        {
            ans.push_back(vec);
            return;
        }
        for(int i = 0; i<num.size(); ++i)
        {
            if(num[i] > left)
                break;
            if(i && num[i]==num[i-1] && !visited[i-1])
                continue;
            if(!visited[i] && (vec.empty() || num[i]>=vec.back()))
            {
                visited[i] = true;
                vec.push_back(num[i]);
                dfs(vec, visited, left-num[i]);
                vec.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        if(num.empty())
            return ans;
        vector<int>vec;
        sort(num.begin(), num.end());
        this->num = num;
        vector<bool>visited(num.size(), false);
        dfs(vec, visited, target);
        return ans;
    }
};
