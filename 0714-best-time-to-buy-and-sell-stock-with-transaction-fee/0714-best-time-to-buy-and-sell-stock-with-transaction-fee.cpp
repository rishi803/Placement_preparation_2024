class Solution {
public:
    
    vector<vector<int>>dp;
    
    int help(vector<int>&prices,int fee , int idx,bool canbuy){
        
        if(idx>=prices.size()) return 0;
        if(dp[idx][canbuy]!=-1) return dp[idx][canbuy];
        int take=0,nottake=0;
        
        if(canbuy){
            take= -prices[idx]+help(prices,fee,idx+1,false);
            nottake= help(prices,fee,idx+1,true);
                
        }
        
        else{
            take= prices[idx]-fee+help(prices,fee,idx+1,true);
            nottake= help(prices,fee,idx+1,false);
            
        }
        
        return dp[idx][canbuy]=max(take,nottake);
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return help(prices,fee,0,true);
    }
};