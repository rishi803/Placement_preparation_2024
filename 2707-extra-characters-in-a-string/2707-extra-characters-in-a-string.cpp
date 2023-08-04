class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int sz=s.size();
        
      vector<int>dp(sz+1);
      dp[0]=0;
        
        for(int i=1;i<=sz;i++){
            dp[i]=1+dp[i-1];
            for(int j=i;j>0;j--){
    
            string temp=s.substr(j-1,i-j+1);
                // cout<<temp<<endl;
                
            if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end()){
                dp[i]=min(dp[i],dp[j-1]);
            }
                
            }
            // cout<<endl;
        }
        
        // for(int i=0;i<=sz;i++){
        //     cout<<dp[i]<<" ";
        // }
        
        return dp[sz]==0?true:false;
    }
};