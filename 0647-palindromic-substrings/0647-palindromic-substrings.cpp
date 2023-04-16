class Solution {
public:
    int countSubstrings(string s) {
          vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        int ans=0;
      
        int k=0;
        for(int cnt=0;cnt<s.size();cnt++){
            int i=0;
            int j=cnt;
            for(int times=0;times<(s.size()-cnt);times++){
                // cout<<times<<" ";
                // cout<<" i= "<<i<<" j= "<<j<<" ";
                int gap=j-i;
                
                if(gap==0){
                    dp[i][j]=true;
                    ans++;
                }
                
                else if(gap==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                        ans++;
                    }
                   
                }
                else{
                    if(dp[i+1][j-1]==true and s[i]==s[j]){
                        dp[i][j]=true;
                        ans++;
                    }
                   
                }
                i++;
                j++;
            }
            // cout<<endl;
        }
        
       return ans;
    }
};