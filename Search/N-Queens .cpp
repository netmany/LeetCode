/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
    bool isSafe(int* layout, int col){
        for(int i = 0; i < col; i++){
            if(layout[i] == layout[col] || abs(layout[i] - layout[col]) == col - i)
                return false;
        }
        return true;
    }
    bool backTrack(int* layout, int* col, int n){
        if(*col < n && layout[*col] < n)
            return true;
        else{
            bool valid;
            do{
                *col = *col - 1;
                valid = *col >= 0;
                if (valid) layout[*col] ++;
            } while (valid && layout[*col] == n);
            return valid;
        }
    }
    void addLayout(vector<vector<string> > &res, int* layout, int n){
        vector<string> p;
        for(int i = 0; i < n; i++){
            string line;
            for(int j = 0; j < n; j++) line += layout[j] == i ? "Q" : ".";
            p.push_back(line);
        }
        res.push_back(p);
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if(n == 0) return res;
        int* layout = new int[n];
        layout[0] = 0;
        int col = 0, count = 0;
        while(true){
            if(isSafe(layout, col)) {
                col++; 
                if(col < n) layout[col] = 0;
                else addLayout(res, layout, n);
            } else {
                layout[col]++;
            }
            if(!backTrack(layout, &col, n))
                break;
        }
        delete layout;
        return res;
    }
};
