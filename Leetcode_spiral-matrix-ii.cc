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

//SECOND TRAIL
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> >ans;
        for(int i = 0; i<n; ++i)
        {
            vector<int>v(n, 0);
            ans.push_back(v);
        }
        int ib = 0, ie = n-1, jb = 0, je = n-1, val = 1;
        while(ib <= ie && jb <= je)
        {
            for(int j = jb; j<=je; ++j)
                ans[ib][j] = val++;
            ++ib;
            for(int i = ib; i<=ie; ++i)
                ans[i][je] = val++;
            --je;
            if(ib > ie || jb > je)
                break;
            for(int j = je; j >= jb; --j)
                ans[ie][j] = val++;
            --ie;
            for(int i = ie; i>=ib; --i)
                ans[i][jb] = val++;
            ++jb;
        }
        return ans;
    }
};
