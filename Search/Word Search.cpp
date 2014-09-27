/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


class Solution {
    bool walk(vector<vector<char> > &board, int x, int y, 
            string &word, int begin, set<pair<int, int> > &path) {
        if(begin == word.length()) return true;
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
            return false;
        pair<int, int> p(x, y);
        if(path.count(p) != 0) return false;
        if(board[x][y] != word[begin]) return false;
        path.insert(p);
        int x1, y1;
        for(int d = 0; d < 4; d++){
            x1 = x, y1 = y;
            switch(d){
                case 0: x1 = x + 1; break;
                case 1: y1 = y + 1; break;
                case 2: x1 = x - 1; break;
                case 3: y1 = y - 1; break;
            }
            if(walk(board, x1, y1, word, begin + 1, path)) return true;
        }
        path.erase(p);
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        set<pair<int, int> > path;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(walk(board, i, j, word, 0, path)) return true;
            }
        }
        return false;
    }
};
