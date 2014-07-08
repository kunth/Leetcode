class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())
            return;
        int row = matrix.size(), col = matrix[0].size();
        bool set_first_row_zero = false, set_first_col_zero = false;
        for(int i = 0; i<row; ++i)
        {
            if(matrix[i][0]==0)
            {
                set_first_col_zero = true;
                break;
            }
        }
        for(int j = 0; j<col; ++j)
        {
            if(matrix[0][j]==0)
            {
                set_first_row_zero = true;
                break;
            }
        }
        for(int i = 1; i<row; ++i)
        {
            for(int j = 1; j<col; ++j)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i<row; ++i)
        {
            if(matrix[i][0]==0)
            {
                for(int j = 0; j<col; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 1; j<col; ++j)
        {
            if(matrix[0][j]==0)
            {
                for(int i = 0; i<row; ++i)
                    matrix[i][j] = 0;
            }
        }
        if(set_first_row_zero)
        {
            for(int j = 0; j<col; ++j)
                matrix[0][j] = 0;
        }
        if(set_first_col_zero)
        {
            for(int i = 0; i<row; ++i)
                matrix[i][0] = 0;
        }
    }
};


//Solution 2, O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())
            return;
        int row = matrix.size(), col = matrix[0].size();
        vector<int>rb(row, false), cb(col, false);
        for(int i = 0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(!matrix[i][j])
                    rb[i] = cb[j] = true;
            }
        }
        for(int i = 0; i<row; ++i)
        {
            if(rb[i])
            {
                for(int j = 0; j<col; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 0; j<col; ++j)
        {
            if(cb[j])
            {
                for(int i = 0; i<row; ++i)
                    matrix[i][j] = 0;
            }
        }
    }
};


//Solution 3, 0(1), almost the same with Solution 1
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty())
            return;
        int row = matrix.size(), col = matrix[0].size();
        bool first_row = false, first_col = false;
        for(int i = 0; i<row; ++i)
        {
            if(!matrix[i][0])
            {
                first_col = true;
                break;
            }
        }
        for(int i = 0; i<col; ++i)
        {
            if(!matrix[0][i])
            {
                first_row = true;
                break;
            }
        }
        for(int i = 0; i<row; ++i)
        {
            for(int j = 0; j<col; ++j)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<row; ++i)
        {
            if(!matrix[i][0])
            {
                for(int j = 1; j<col; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 1; j<col; ++j)
        {
            if(!matrix[0][j])
            {
                for(int i = 1; i<row; ++i)
                    matrix[i][j] = 0;
            }
        }
        if(first_row)
        {
            for(int i = 0; i<col; ++i)
                matrix[0][i] = 0;
        }
        if(first_col)
        {
            for(int i = 0; i<row; ++i)
                matrix[i][0] = 0;
        }
    }
};
