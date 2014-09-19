class Solution {
private:
    int row, col;
public:
    void bfs(int r, int c, vector<vector<char>>&board)
    {
        board[r][c] = 'Y';
        queue<pair<int, int>>q;
        q.push(pair<int, int>(r, c));
        pair<int, int>cur;
        while(!q.empty())
        {
            cur = q.front();
            q.pop();
            if(cur.first+1<row && board[cur.first+1][cur.second]=='O')
            {
                board[cur.first+1][cur.second] = 'Y';
                q.push(pair<int, int>(cur.first+1, cur.second));
            }
            if(cur.second+1<col && board[cur.first][cur.second+1]=='O')
            {
                board[cur.first][cur.second+1] = 'Y';
                q.push(pair<int, int>(cur.first, cur.second+1));
            }
            if(cur.first-1>=0 && board[cur.first-1][cur.second]=='O')
            {
                board[cur.first-1][cur.second] = 'Y';
                q.push(pair<int, int>(cur.first-1, cur.second));
            }
            if(cur.second-1>=0 && board[cur.first][cur.second-1]=='O')
            {
                board[cur.first][cur.second-1] = 'Y';
                q.push(pair<int, int>(cur.first, cur.second-1));
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        if(!board.empty())
        {
            row = board.size();
            col = board[0].size();
            if(row<=2 || col<=2)
                return;
            for(int i = 0; i < row; ++i)
            {
                if(board[i][0]=='O')
                    bfs(i, 0, board);
                if(board[i][col-1]=='O')
                    bfs(i, col-1, board);
            }
            for(int j = 1; j < col - 1; ++j)
            {
                if(board[0][j]=='O')
                    bfs(0, j, board);
                if(board[row-1][j]=='O')
                    bfs(row-1, j, board);
            }

            for(int i=0; i<row; ++i)
            {
                for(int j=0; j<col; ++j)
                {
                    if(board[i][j]=='O')
                        board[i][j] = 'X';
                    else if(board[i][j]=='Y')
                        board[i][j] = 'O';
                }
            }
        }
    }
};

//Second trial, almost the same
class Solution {
private:
    int row, col;
    void search(vector<vector<char>> &board, int i, int j) {
        board[i][j] = 'Y';
        queue<pair<int, int>>q;
        q.push(pair<int, int>(i, j));
        pair<int, int> cur;
        while(!q.empty()) {
          cur = q.front();
          q.pop();
          if(cur.first+1<row && board[cur.first+1][cur.second]=='O') {
            q.push(pair<int, int>(cur.first+1, cur.second));
            board[cur.first+1][cur.second] = 'Y';
          }
          if(cur.second+1<col && board[cur.first][cur.second+1]=='O'){
            q.push(pair<int, int>(cur.first, cur.second+1));
            board[cur.first][cur.second+1] = 'Y';
          }
          if(cur.first-1>=0 && board[cur.first-1][cur.second]=='O'){
            q.push(pair<int, int>(cur.first-1, cur.second));
            board[cur.first-1][cur.second] = 'Y';
          }
          if(cur.second-1>=0 && board[cur.first][cur.second-1]=='O'){
            q.push(pair<int, int>(cur.first, cur.second-1));
            board[cur.first][cur.second-1] = 'Y';
          }
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        if(board.empty())
            return;
        row = board.size();
        col = board[0].size();
        bool flag;
        for(int i = 0; i<row; ++i) {
            for(int j = 0; j<col; ++j) {
              if(!i || !j || i==row-1 || j==col-1) {
                if(board[i][j]=='O')
                  search(board, i, j);
              }
            }
        }

        for(int i = 0; i<row; ++i) {
          for(int j = 0; j<col; ++j) {
            if(board[i][j]=='Y')
              board[i][j] = 'O';
            else if(board[i][j]=='O')
              board[i][j] = 'X';
          }
        }

    }
};
