class Solution {
public:
    void dfs(vector<vector<int>>&ans, vector<int>&S, vector<bool>&visited, vector<int>vec, int st)
    {
        if(st == S.size())
        {
            if(find(ans.begin(), ans.end(), vec)==ans.end())
                ans.push_back(vec);
            return;
        }
        dfs(ans, S, visited, vec, st+1);
        if(visited[st])
            return;
        vec.push_back(S[st]);
        visited[st] = true;
        dfs(ans, S, visited, vec, st+1);
        visited[st] = false;
        vec.pop_back();
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>>ans;
        if(S.empty())
            return ans;
        sort(S.begin(), S.end());
        vector<int>vec;
        vector<bool>visited(S.size(), false);
        dfs(ans, S, visited, vec, 0);
        return ans;
    }
};

//Solution Two
class Solution {
    void dfs(vector<vector<int> >&ans, vector<int>&S, vector<int>&vec, vector<bool>&visited, int step){
        if(step==S.size()){
            ans.push_back(vec);
            return;
        }
        if(step && S[step] == S[step-1] && !visited[step-1]){
            dfs(ans, S, vec, visited, step+1);
            return;
        }
        vec.push_back(S[step]);
        visited[step] = true;
        dfs(ans, S, vec, visited, step+1);
        visited[step] = false;
        vec.pop_back();
        dfs(ans, S, vec, visited, step+1);
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> >ans;
        sort(S.begin(), S.end());
        vector<bool>visited(S.size(), false);
        vector<int>vec;
        dfs(ans, S, vec, visited, 0);
        return ans;
    }
};
