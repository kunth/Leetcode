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


//Solution Two

class Solution {
private:
    bool rowArr[9], colArr[9], nineGrid[9];
    bool checkRow(vector<vector<char> > &board, int row){
        if(rowArr[row])
            return true;
        vector<bool>vec(10, false);
        for(int i = 0; i<9; ++i) {
            if(board[row][i]=='.')
                    continue;
            if(vec[board[row][i]-'0'])
                return false;
            vec[board[row][i]-'0'] = true;
        }
        rowArr[row] = true;
        return true;
    }
    bool checkCol(vector<vector<char> > &board, int col) {
        if(colArr[col])
            return true;
        vector<bool>vec(10, false);
        for(int i = 0; i<9; ++i) {
            if(board[i][col]=='.')
                    continue;
            if(vec[board[i][col]-'0'])
                return false;
            vec[board[i][col]-'0'] = true;
        }
        colArr[col] = true;
        return true;
    }
    bool checkNineGrid(vector<vector<char> > &board, int row, int col) {
        int cnt = (row / 3)*3 + col / 3;
        if(nineGrid[cnt])
            return true;
        vector<bool>vec(10, false);
        for(int i = row / 3 * 3; i <= row / 3 * 3  + 2; ++i) {
            for(int j = col / 3 * 3; j <= col / 3 * 3 + 2; ++j) {
                if(board[i][j]=='.')
                    continue;
                if(vec[board[i][j]-'0'])
                    return false;
                vec[board[i][j]-'0'] = true;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        memset(rowArr, false, sizeof(rowArr));
        memset(colArr, false, sizeof(colArr));
        memset(nineGrid, false, sizeof(nineGrid));
        for(int i = 0; i<9; ++i) {
            for(int j = 0; j<9; ++j) {
                if(board[i][j]!='.') {
                    if(!checkRow(board, i) || !checkCol(board, j) || !checkNineGrid(board, i, j))
                        return false;
                }
            }
        }
        return true;
    }
};
