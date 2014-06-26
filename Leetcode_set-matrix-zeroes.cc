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
