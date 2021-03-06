//http://oj.leetcode.com/problems/pascals-triangle/submissions/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >res;
        if(numRows)
        {
            for(int i = 0; i<numRows; ++i)
            {
                vector<int>vec;
                for(int j = 0; j <=i; ++j)
                {
                    if(j==0 || j==i)
                    {
                        vec.push_back(1);
                    }
                    else
                    {  
                        vec.push_back(res[i-1].at(j)+res[i-1].at(j-1));
                    }
                }
                res.push_back(vec);
            }
            
        }
        return res;
    }
};

//SECOND TRIAL
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >ans;
        if(numRows<=0)
            return ans;
        for(int i = 0; i<numRows; ++i)
        {
            vector<int>vec(i+1, 1);
            for(int j = 0; j <= i; ++j)
            {
                if(j>0 && j<i)
                    vec[j] = ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
