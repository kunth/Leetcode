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
