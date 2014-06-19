class Solution {
public:
    void dfs(vector<vector<int>>&ans, vector<bool>visited, vector<int>vec, const vector<int>&num)
    {
        if(vec.size()==num.size())
        {
            ans.push_back(vec);
            return;
        }
        for(int i = 0; i<num.size(); ++i)
        {
            if(i && num[i]==num[i-1] && !visited[i-1])
                continue;
            if(!visited[i])
            {
                visited[i] = true;
                vec.push_back(num[i]);
                dfs(ans, visited, vec, num);
                vec.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> >ans;
        if(num.empty())
            return ans;
        vector<bool>visited(num.size(), false);
        vector<int>vec;
        dfs(ans, visited, vec, num);
        return ans;
    }
};

//SECOND TRIAL, almost the same
class Solution {
private:
    vector<int>num;
    void dfs(vector<vector<int> >&ans, vector<int>vec, vector<bool>visited)
    {
        if(vec.size()==num.size())
        {
            ans.push_back(vec);
            return;
        }
        for(int i = 0; i<num.size(); ++i)
        {
            if(!visited[i])
            {
                visited[i] = true;
                vec.push_back(num[i]);
                dfs(ans, vec, visited);
                vec.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> >ans;
        if(num.empty())
            return ans;
        this->num = num;
        vector<int>vec;
        vector<bool>visited(num.size(), false);
        dfs(ans, vec, visited);
        return ans;
    }
};
