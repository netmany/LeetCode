/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
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
public:
    int totalNQueens(int n) {
        int* layout = new int[n];
        layout[0] = 0;
        int col = 0, count = 0;
        while(true){
            if(isSafe(layout, col)) {
                col++; 
                if(col < n) layout[col] = 0;
                else count++;
            } else {
                layout[col]++;
            }
            if(!backTrack(layout, &col, n))
                break;
        }
        delete layout;
        return count;
    }
};
