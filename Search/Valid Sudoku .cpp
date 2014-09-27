/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

*/


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int s = board.size();
        for(int i = 0; i < s; i++){
            set<char> row;
            for(int j = 0; j < s; j++){
                if(board[i][j] == '.') continue;
                if(row.count(board[i][j]) != 0) return false;
                else row.insert(board[i][j]);
            }
        }
        for(int j = 0; j < s; j++){
            set<char> col;
            for(int i = 0; i < s; i++){
                if(board[i][j] == '.') continue;
                if(col.count(board[i][j]) != 0) return false;
                else col.insert(board[i][j]);
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                set<char> sqr;
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        int r = i * 3 + k, c = j * 3 + l;
                        if(board[r][c] == '.') continue;
                        if(sqr.count(board[r][c]) != 0) return false;
                        else sqr.insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};
