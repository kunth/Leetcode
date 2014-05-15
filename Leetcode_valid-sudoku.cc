class Solution {
public:
    bool is_fill(vector<vector<char>>&board, int row, int col, char ch)
    {
        for(int i = 0; i<9; ++i)
        {
            if((i!=row && board[i][col]==ch)||(i!=col && board[row][i]==ch))
                return false;
        }
        int left_row, left_col, right_row, right_col;
        if(row % 3 ==2)
        {
            left_row = row-2;
            right_row = row;
        }
        else if(row % 3 ==1)
        {
            left_row = row-1;
            right_row = row+1;
        }
        else
        {
            left_row = row;
            right_row = row+2;
        }
       
        if(col % 3 ==2)
        {
            right_col = col;
            left_col = col-2;
        }
        else if(col % 3 ==1)
        {
            left_col = col-1;
            right_col = col+1;
        }
        else
        {
            left_col = col;
            right_col = col + 2;
        }
        for(int i = left_row; i<=right_row; ++i)
            for(int j = left_col; j<=right_col; ++j)
                if(i!=row && j!=col && board[i][j]==ch)
                    return false;
        return true;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        if(board.empty() || board.size()!=9)
            return false;
       
        for(int i = 0; i<board.size(); ++i)
        {
            for(int j = 0; j<board[i].size(); ++j)
            {
                if(board[i][j]!='.' && !is_fill(board, i, j, board[i][j]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
