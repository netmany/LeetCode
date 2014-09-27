/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
*/


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        for(int start = 0; start < n; start++){
            int p = 0, j = 0;
            for(; j < n; j++){
                p += gas[(start + j) % n] - cost[(start + j) % n];
                if(p < 0) break;
            }
            if(j == n) return start;
        }
        return -1;
    }
};
