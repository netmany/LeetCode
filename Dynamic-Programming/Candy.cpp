/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/


class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.size() == 0) return 0;
        vector<int> cand(ratings.size(), 0);
        cand[0] = 1; int lv = 1;
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1]) lv++;
            else lv = 1;
            cand[i] = lv; 
        }
        lv = 1;
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) lv++;
            else lv = 1;
            cand[i] = max(cand[i], lv);
        }
        int s = 0;
        for(int i = 0; i < cand.size(); i++){
            s += cand[i];
        }
        return s;
    }
};
