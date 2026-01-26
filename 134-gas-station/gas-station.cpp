class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cost_sum = 0 , gas_sum = 0, n = gas.size();
        for(int i = 0; i<n; i++) {
            cost_sum += cost[i];
            gas_sum += gas[i];
        }
        if(gas_sum < cost_sum) return -1;
        int idx = 0 , fuel = 0;
        for(int i = 0; i<n; i++) {
            fuel += gas[i] - cost[i];
            if(fuel < 0) {
                idx = i+1;
                fuel = 0;
            }
        }
        return idx;
    }
};