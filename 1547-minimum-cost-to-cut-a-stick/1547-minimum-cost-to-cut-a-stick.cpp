class Solution {
public:
    
    int help(vector<int>&cuts,int leftidx,int rightidx,int st,int end,vector<vector<int>>&dp){
        
        if(st>end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        
        int ans=INT_MAX;
        
        for(int i=st;i<=end;i++){
            
            int leftcost=help(cuts,leftidx,cuts[i],st,i-1,dp);
            int rightcost=help(cuts,cuts[i],rightidx,i+1,end,dp);
            
            ans=min(ans,rightidx-leftidx+leftcost+rightcost);
        }
        
        return dp[st][end]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size(),-1));
        sort(cuts.begin(),cuts.end());
        return help(cuts,0,n,0,cuts.size()-1,dp);
    }
};