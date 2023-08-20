class Solution {
public:
    
    // n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
    
    
         vector<int> dp;
    
    int help(vector<vector<int>>&offers, int n, int currhouse){
        if(currhouse >= offers.size()) return 0;
        if(dp[currhouse] != -1) return dp[currhouse];
        
        int take=0, nottake=0;
        vector<int>v(3,1e6);
        v[0]= offers[currhouse][1];
        
        int nexthouse= lower_bound(offers.begin(),offers.end(), v) - offers.begin();
      
            take+= offers[currhouse][2] + help(offers, n, nexthouse);
            nottake+= help(offers, n, currhouse+1);

       
        
        return dp[currhouse]= max(take, nottake);
        
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());   // [[0,0,5],[3,3,1],[1,2,5],[0,0,7]]
        dp.assign(offers.size(), -1);
        return help(offers, n, 0);
    }
};