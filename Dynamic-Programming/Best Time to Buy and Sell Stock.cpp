/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/


class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int s = 0;
        if(prices.size() < 1) return 0;
        int m = prices[0];
        for(int i = 1; i < prices.size(); i++){
            s = max(s, prices[i] - m);
            m = min(m, prices[i]);
        }
        return s;
    }
};
