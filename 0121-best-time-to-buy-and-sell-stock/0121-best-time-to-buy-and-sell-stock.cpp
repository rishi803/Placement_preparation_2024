class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mn=prices[0];
        int maxprofit=0;
        
        for(auto &i:prices){
            
            int profit=i-mn;
            maxprofit=max(maxprofit,profit);
            mn=min(mn,i);
        }
        
        return maxprofit;
    }
};