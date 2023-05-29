class Solution {
public:
    
    int dp[100001][3];
    const int m=int(1e9+7);
    
    int help(string &cor,int idx,int chair){
        if(idx>=cor.size()){
            return chair==2;
        }
        if(dp[idx][chair]!=-1) return dp[idx][chair];
        
        int ans=0;
        
    
      if(chair==2){
          if(cor[idx]=='S') ans= help(cor,idx+1,1);
          else{
              ans=(help(cor,idx+1,0)%m+help(cor,idx+1,chair)%m)%m;
          }
      }
        else{
            if(cor[idx]=='S') ans=help(cor,idx+1,chair+1);
            else ans=help(cor,idx+1,chair)%m;
        }
        return dp[idx][chair]=ans;
    }
    int numberOfWays(string cor) {
        
        memset(dp,-1,sizeof(dp));
        return help(cor,0,0);
    }
};