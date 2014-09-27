/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/


class Solution {
    void bfs(vector<vector<char>> &board, int x, int y){
        queue<pair<int, int> > q;
        q.push(pair<int, int>(x, y));
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            int x = p.first, y = p.second;
            if(x < 0 || x > board.size() - 1 
                || y < 0 || y > board[0].size() - 1
                || board[x][y] != 'O') 
                continue;
            board[x][y] = 'T';
            q.push(pair<int, int>(x - 1, y));
            q.push(pair<int, int>(x + 1, y));
            q.push(pair<int, int>(x , y - 1));
            q.push(pair<int, int>(x , y + 1));
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            bfs(board, i, 0);
            bfs(board, i, n - 1);
        }
        for(int j = 0; j < n; j++){
            bfs(board, 0, j);
            bfs(board, m - 1, j);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
        
    }
};
