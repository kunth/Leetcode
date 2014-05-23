class Solution {
public:
    int row, col;
    bool dfs(vector<vector<char> >&map, int pos_row, int pos_col, string word, int left_len)
    {
        if(!left_len)
            return true;
        char dest_ch = word[word.length()-left_len];
        if(pos_row+1<this->row && map[pos_row+1][pos_col]==dest_ch)
        {
            map[pos_row+1][pos_col]='*';
            if(dfs(map, pos_row+1, pos_col, word, left_len-1))
                return true;
            map[pos_row+1][pos_col]=dest_ch;
        }
        if(pos_row-1>=0 && map[pos_row-1][pos_col]==dest_ch)
        {
            map[pos_row-1][pos_col]='*';
            if(dfs(map, pos_row-1, pos_col, word, left_len-1))
                return true;
            map[pos_row-1][pos_col]=dest_ch;
        }
        if(pos_col+1<this->col && map[pos_row][pos_col+1]==dest_ch)
        {
            map[pos_row][pos_col+1]='*';
            if(dfs(map, pos_row, pos_col+1, word, left_len-1))
                return true;
            map[pos_row][pos_col+1]=dest_ch;
        }
        if(pos_col-1>=0 && map[pos_row][pos_col-1]==dest_ch)
        {
            map[pos_row][pos_col-1]='*';
            if(dfs(map, pos_row, pos_col-1, word, left_len-1))
                return true;
            map[pos_row][pos_col-1]=dest_ch;
        }
        return false;
    }
   
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || word.empty())
            return false;
        this->row = board.size();
        this->col = board[0].size();
               
        for(int i = 0; i<this->row; ++i)
        {
            for(int j = 0; j<this->col; ++j)
            {
                if(board[i][j]==word[0])
                {
                    board[i][j]='*';
                    if(dfs(board, i, j, word, word.length()-1))
                        return true;
                    board[i][j]=word[0];
                }
            }
        }
        return false;
    }
};
