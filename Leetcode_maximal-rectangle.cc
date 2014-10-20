class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>>dp;
        for(int i = 0; i<row; ++i)
        {
            vector<int>vec(col, 0);
            dp.push_back(vec);
            for(int j=0; j<col; ++j)
            {
                if(j==0)
                    dp[i][j] = matrix[i][j]=='1' ? 1 : 0;
                else
                    dp[i][j] = matrix[i][j]=='1' ? dp[i][j-1] + 1 : 0;
            }
        }
        int ans = 0;
        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                int width = dp[i][j];
                if(width>0)
                {
                    for(int cnt = i; cnt>=0 && width>0; --cnt)
                    {
                        width = min(width, dp[cnt][j]);
                        ans = max(ans, width*(i-cnt+1));
                    }
                }
            }
        }
        return ans;
    }
};


//Another trial
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int> >dp(row, vector<int>(col, 0));
        for(int i = 0; i<row; ++i)
            if(matrix[i][0]=='1')
                dp[i][0] = 1;
                
        for(int i = 0; i<row; ++i)
            for(int j = 1; j<col; ++j)
                if(matrix[i][j]=='1')
                    dp[i][j] = dp[i][j-1]+1;
        
        int minWidth, ans = 0;
        for(int i = 0; i<row; ++i) {
            for(int j = 0; j<col; ++j) {
                minWidth = col;
                for(int k = i; k>=0; --k) {
                    if(!dp[k][j])
                        break;
                    minWidth = min(minWidth, dp[k][j]);
                    ans = max(ans, minWidth*(i-k+1));
                }
            }
        }
        return ans;
    }
};

//O(n^2) solution
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size(), ans = 0;
        vector<int>dp(col, 0);
        stack<int>st;
        for(int i = 0; i<row; ++i) {
            int pos;
            for(int j = 0; j<col; ++j) {
                dp[j] = matrix[i][j]=='1' ? dp[j] + 1 : 0;
                while(!st.empty() && dp[j]<dp[st.top()]) {
                    pos = st.top();
                    st.pop();
                    ans = max(ans, dp[pos] * (st.empty() ? j : j-1-st.top()));
                }
                st.push(j);
            }
            while(!st.empty()) {
                pos = st.top();
                st.pop();
                ans = max(ans, dp[pos] * (st.empty() ? col : col-1-st.top()));
            }
        }
        return ans;
    }
};
