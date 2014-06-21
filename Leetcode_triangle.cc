class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        int row = triangle.size();
        for(int i = 1; i < row; ++i)
        {
            for(int j=0; j<=i; ++j)
            {
                if(j==0)
                    triangle[i][j]+=triangle[i-1][j];
                else if(j==i)
                    triangle[i][j]+=triangle[i-1][j-1];
                else
                    triangle[i][j]+=min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int ans = triangle[row-1][0];
        for(int i=0; i<row; ++i)
        {
            ans = ans > triangle[row-1][i] ? triangle[row-1][i] : ans;
        }
        return ans;
    }
};

//SECOND TRIAL
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        int sz = triangle.size();
        for(int i = 1; i<sz; ++i)
        {
            for(int j = 0; j<=i; ++j)
            {
                if(j==0)
                    triangle[i][j] += triangle[i-1][0];
                else if(j==i)
                    triangle[i][j] += triangle[i-1][i-1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int ans = triangle[sz-1][0];
        for(int i = 1; i<sz; ++i)
            ans = min(ans, triangle[sz-1][i]);
        return ans;
    }
};
