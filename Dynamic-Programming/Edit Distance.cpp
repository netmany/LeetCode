/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int> > dist(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = len1 -1; i >= 0; i--){
            dist[i][len2] = len1 - i;
        }
        for(int i = len2 -1; i >= 0; i--){
            dist[len1][i] = len2 - i;
        }
        for(int i = len1 -1; i >= 0; i--){
            for(int j = len2 -1; j >= 0; j--){
                if(word1[i] == word2[j]) dist[i][j] = dist[i + 1][j + 1];
                else dist[i][j] = 1 + min(min(dist[i + 1][j + 1], dist[i][j + 1]), dist[i + 1][j]);
            }
        }
        return dist[0][0];
    }
};
