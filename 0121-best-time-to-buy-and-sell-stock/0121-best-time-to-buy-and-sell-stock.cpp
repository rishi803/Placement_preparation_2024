class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mx=0,costp=prices[0];
        
        for(int i=1; i<prices.size(); i++){
            costp= min(costp, prices[i]);
            mx= max(mx, prices[i]-costp);
        }
        
        return mx;
    }
};