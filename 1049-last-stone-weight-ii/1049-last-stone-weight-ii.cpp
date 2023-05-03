class Solution {
public:
    
    int dp[31][6002];                                         // to convert -ve indexs to positive 
    int help(vector<int>&stones,int value,int idx){
        
        if(idx==stones.size()) {
            if(value<0) return INT_MAX-1000;
            else return 0;
        }
        
        if(dp[idx][value+3001]!=-1) return dp[idx][value+3001];
        
        int pos=stones[idx]+help(stones,value+stones[idx],idx+1);
        int neg=-stones[idx]+help(stones,value-stones[idx],idx+1);
        
        return dp[idx][value+3001]=min(pos,neg);
        
    }
    int lastStoneWeightII(vector<int>& stones) {
        
        memset(dp,-1,sizeof(dp));
        return help(stones,0,0);
    }
};