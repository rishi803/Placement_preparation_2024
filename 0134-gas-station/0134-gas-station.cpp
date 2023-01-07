class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stidx=0,fuel=0,cnt=0,gas_plus_cost=0;
        
        for(int i=0;i<gas.size();i++){
            int cgas=gas[i];
            int ccost=cost[i];
            
            fuel=fuel+cgas-ccost;
            gas_plus_cost+=cgas-ccost;
            
            if(fuel<0){
                fuel=0;
                stidx=i+1;
            }

                
        }
        if(gas_plus_cost<0) return -1;
        return stidx;
    }
};