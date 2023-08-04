class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        unordered_map<string,int>mp;
        for(auto str: dictionary){
            mp[str] = 1;
        }
        
        vector<int>dp(s.size()+1);
        dp[0]=1;
        
        for(int i=0; i<s.size(); i++){
            if(i!=0) dp[i] = 1 + dp[i-1];
            
         for(int j=i; j>=0; j--){
             
             string str= s.substr(j, i-j+1);
             if(mp[str] > 0){
                 
                 if(j==0) dp[i]=0;
                 else
                 dp[i]= min(dp[i] , dp[j-1]);
             }
         }
            
       }
        
        return dp[s.size()-1];
    }
};