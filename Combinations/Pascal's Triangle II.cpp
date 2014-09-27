/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        for(int i = 0; i< rowIndex+1; i++){
            for(int j = v.size() - 1; j >= 1; j--){
                v[j] += v[j-1];
            }
            v.push_back(1);
        }
        return v;
    }
};
