/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> s; s.insert(num.begin(), num.end());
        int m = 1;
        for(int i = 0; i < num.size(); i++){
            int t = 1, p;
            p = num[i] -1;
            while(s.count(p) > 0) {
                t++; s.erase(p); p--;
            }
            p = num[i] +1;
            while(s.count(p) > 0) {
                t++; s.erase(p); p++;
            }
            m = max(m, t);
        }
        return m;
    }
};
