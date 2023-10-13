

class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        int cur=0;
       int secprev=cost[0];
       int prev=cost[1];
        
        for(int i=2;i<n;i++){
            
           cur=cost[i]+min(prev,secprev);
           secprev=prev;
            prev=cur;
            
        }
        
        return min(prev,secprev);
    }
};