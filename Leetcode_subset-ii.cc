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

