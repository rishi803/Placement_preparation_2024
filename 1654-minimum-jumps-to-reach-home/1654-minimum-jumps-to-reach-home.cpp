class Solution {
public:
    unordered_map<int,int>cant_go;
    int dp[7001][2];
    
    int help(int a,int b,int x,int st, bool cangobackward){
        
        if(st==x) return 0;
        if(st<0  or cant_go.find(st)!=cant_go.end() or st>6000) return 1e9;
        
        if(dp[st][cangobackward]!=-1) return dp[st][cangobackward];
        
        dp[st][cangobackward]= 1+help(a,b,x,st+a,true);
        
        if(cangobackward)
        dp[st][cangobackward]=min(dp[st][cangobackward],1+help(a,b,x,st-b,false));
        
        return dp[st][cangobackward];
    }
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(int i=0;i<forbidden.size();i++){
            cant_go[forbidden[i]]=1;
        }
        memset(dp,-1,sizeof(dp));
        bool cangobackward=true;
        
        int ans= help(a,b,x,0,cangobackward);
        return ans>=1e9?-1:ans;
    }
};