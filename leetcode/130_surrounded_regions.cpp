class Solution {
public:
    void segment(int i, int j, vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
                    
        while(!q.empty()) {
            const auto& c = q.front();
            q.pop();
            
            int ci = c.first, cj = c.second;
            
            board[ci][cj] = '.';
                        
            if(ci > 0 && board[ci - 1][cj] == 'O') {
                board[ci - 1][cj] = '.';
                q.push(make_pair(ci - 1, cj));
            }
            
            if(cj > 0 && board[ci][cj - 1] == 'O') {
                board[ci][cj - 1] = '.';
                q.push(make_pair(ci, cj - 1));
            }
            
            if(ci < board.size() - 1 && board[ci + 1][cj] == 'O') {
                board[ci + 1][cj] = '.';
                q.push(make_pair(ci + 1, cj));
            }
            
            if(cj < board.front().size() - 1 && board[ci][cj + 1] == 'O') {
                board[ci][cj + 1] = '.';
                q.push(make_pair(ci, cj + 1));
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty() || board.front().empty())
            return;
        
        int max_row = board.size() - 1;
        int max_col = board.front().size() - 1;
        
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O')
                segment(i, 0, board);
            if(board[i][max_col] == 'O')
                segment(i, max_col, board);
        }
        
        for(int j = 0; j < board.front().size(); j++) {
            if(board[0][j] == 'O')
                segment(0, j, board);
            if(board[max_row][j] == 'O')
            segment(max_row, j, board);
        }
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.front().size(); j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '.')
                    board[i][j] = 'O';
            }
        }
    }
};
