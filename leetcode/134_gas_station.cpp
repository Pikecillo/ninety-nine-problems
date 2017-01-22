class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num_stations = gas.size();
        int start = 0, deficit = 0, tank = 0;
        
        for(int i = 0; i < num_stations; i++) {
            if(tank < 0) {
                deficit += tank;
                tank = 0;
                start = i;
            }
            
            tank += (gas[i] - cost[i]);
        }
        
        return (deficit + tank) >= 0 ? start : -1;
    }
};
