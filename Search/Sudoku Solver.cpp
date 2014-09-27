/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/


class Solution {
    bool isValid(vector<vector<char> > &board, int i, int j){
        int r = (i / 3) * 3, c = (j / 3) * 3;
        for(int k = 0; k < 9; k++){
            if(k != j && board[i][k] == board[i][j]) return false;
            if(k != i && board[k][j] == board[i][j]) return false;
            int p = r + k / 3, q = c + k % 3;
            if(!(p == i && q == j) && board[p][q] == board[i][j]) return false;
        }
        return true;
    }
    bool solv(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                for(int p = 0; p < 9; p++) {
                    board[i][j] = p + '1';
                    if(isValid(board, i, j) && solv(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        solv(board);
    }
};
