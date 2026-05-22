class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int n = gas.size();
        for(int i=0; i<n; i++){
            totalCost += cost[i];
            totalGas += gas[i];
        }

        if(totalGas < totalCost) return -1;
        int currGas = 0;
        int start = 0;
        for(int i=0; i<n; i++){
            currGas = currGas + gas[i] - cost[i];
            if(currGas < 0){
                start = i + 1;
                currGas = 0;
            }
        }

        return start;
    }
};