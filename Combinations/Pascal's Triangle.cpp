/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> pre;
        for(int i = 0; i < numRows; i++){
            if(i > 0) pre = v[i-1];
            vector<int> cur; 
            cur.push_back(1);
            for(int j = 1; j < pre.size(); j++){
                cur.push_back(pre[j] + pre[j - 1]);
            }
            if(i > 0) cur.push_back(1);
            v.push_back(cur);
        }
        return v;
    }
};
