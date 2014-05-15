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
    bool dfs(vector<vector<char>>&board, int row, int col, int left)
    {
        if(!left)
            return true;
        if(board[row][col]!='.')
        {
            if(row < board.size()-1 && col<board.size()-1)
                return dfs(board, row, col+1, left);
            else if(row < board.size()-1)
                return dfs(board, row+1, 0, left);
            else if(col < board.size()-1)
                return dfs(board, row, col+1, left);
            else   
                return false;
        }
        else
        {
            for(char ch = '1'; ch<='9'; ++ch)
            {
                if(is_fill(board, row, col, ch))
                {
                    board[row][col]=ch;
                    if(row < board.size()-1 && col<board.size()-1)
                    {
                        if(dfs(board, row, col+1, left-1))
                            return true;
                    }
                    else if(row < board.size()-1)
                    {
                        if(dfs(board, row+1, 0, left-1))
                            return true;
                    }else if(col<board.size()-1)
                    {
                        if(dfs(board, row, col+1, left-1))
                            return true;
                    }
                    else if(left==1)
                        return true;
                    else
                        return false;
                    board[row][col]='.';
                }
            }
            return false;
        }
    }

    void solveSudoku(vector<vector<char> > &board) {
        if(board.empty() || board.size()!=9)
            return;
        int left = 0;
        for(int i = 0; i<board.size(); ++i)
        {
            for(int j = 0; j<board.size(); ++j)
            {
                if(board[i][j]=='.')
                    ++left;
            }
        }
        dfs(board, 0, 0, left);
    }
};
