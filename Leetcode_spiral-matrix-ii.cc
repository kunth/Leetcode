class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> >res;
        if(!n)
            return res;
        n = n>0? n : -n;
        for(int k = 0; k < n; ++k)
        {
            vector<int>tmpvec;
            for(int p = 0; p < n; ++p)
            {
                tmpvec.push_back(0);
            }
            res.push_back(tmpvec);
        }
        int i = 0, j = 0, cnt = 1;
        while(cnt <= n*n)
        {
            while(j<n && !res[i][j])
                res[i][j++]=cnt++;
            ++i;
            --j;
            while(i<n && !res[i][j])
                res[i++][j]=cnt++;
            --j;
            --i;
            while(j>=0 && !res[i][j])
                res[i][j--]=cnt++;
            --i;
            ++j;
            while(i>=0 && !res[i][j])
                res[i--][j]=cnt++;
            ++j;
            ++i;
        }
        return res;
    }
};
