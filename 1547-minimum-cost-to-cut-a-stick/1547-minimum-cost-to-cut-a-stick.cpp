class Solution {
public:
    

    int help(int st,int end,vector<int>&cuts,int leftidx,int rightidx,vector<vector<int>>&dp){
        
        if(leftidx>rightidx) return 0;
        if(dp[leftidx][rightidx]!=-1) return dp[leftidx][rightidx];
        
        int ans=INT_MAX;
        
        for(int i=leftidx;i<=rightidx;i++){
            int leftcost=help(st,cuts[i],cuts,leftidx,i-1,dp);
            int rightcost=help(cuts[i],end,cuts,i+1,rightidx,dp);
            
            ans=min(ans,end-st+leftcost+rightcost);
        }
        
        return dp[leftidx][rightidx]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        sort(cuts.begin(),cuts.end());
        return help(0,n,cuts,0,cuts.size()-1,dp);
    }
};