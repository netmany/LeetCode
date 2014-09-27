/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len == 0) return 0;
        vector<int> before(len, 0), after(len, 0);
        int low = prices[0], high = prices[len - 1];
        for(int i = 1; i < len; i++){
            before[i] = max(before[i - 1], prices[i] - low);
            low = min(low, prices[i]);
            after[len - 1 - i] = max(after[len - i], high - prices[len - 1 - i]);
            high = max(high, prices[len - 1 - i]);
        }
        int mp = 0;
        for(int i = 0; i < len; i++){
            mp = max(mp, before[i] + after[i]);
        }
        return mp;
    }
};
