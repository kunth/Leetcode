vector<vector<int> >res;
void func(vector<int>&vec, vector<int>subres)
{
     if(vec.empty())
     {
         sort(subres.begin(), subres.end());
         res.push_back(subres);
         return;
     }
     vector<int>subvec(vec.begin(), vec.end()-1);
     subres.push_back(vec.back());
     func(subvec, subres);
     subres.pop_back();
     func(subvec, subres);
}

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        res.clear();
        if(!S.empty())
        {
            vector<int>subres;
            func(S, subres);
        }
        return res;
    }
};

//Solution Two
class Solution {
private:
    void dfs(vector<vector<int> >&ans, vector<int> &S, vector<int>&subset, int step){
        if(step == S.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(S[step]);
        dfs(ans, S, subset, step+1);
        subset.pop_back();
        dfs(ans, S, subset, step+1);
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> >ans;
        if(S.empty())
            return ans;
        vector<int>subset;
        sort(S.begin(), S.end());
        dfs(ans, S, subset, 0);
        return ans;
    }
};
