//check bfs+dp
// switching to lane is interesting here (trick with mod value)

class Solution {
public:
    
    int n;

    int help(int lane,int i,vector<int>&ob,vector<vector<int>>& dp)
    {
        
        if(i==n-1)
            return 0;
        if(ob[i]==lane+1)
            return INT_MAX;
        if(dp[i][lane]!=-1)
            return dp[i][lane];
        if(ob[i+1]!=lane+1)       // 1 step piche hi check krna pdega vrna age bdh jaoge to piche nhi a paoge
            return dp[i][lane]=help(lane,i+1,ob,dp);
        else
        return dp[i][lane]=1+min(help((lane+1)%3,i,ob,dp),help((lane+2)%3,i,ob,dp)); // otherwise lane change and  take minimum of other two lanes
    }
    int minSideJumps(vector<int>& obstacles) {
        n=obstacles.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return help(1,0,obstacles,dp);
        
    }
};