class Solution {
public:
    string longestPalindrome(string s) {
       vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        int mx=0,x=0,y=0;
        string ans;
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
                }
                
                else if(gap==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                         if(gap>mx){
                            mx=gap;
                            x=i;
                            y=j;
                        }
                    }
                   
                }
                else{
                    if(dp[i+1][j-1]==true and s[i]==s[j]){
                        dp[i][j]=true;
                        if(gap>mx){
                            mx=gap;
                            x=i;
                            y=j;
                        }
                    }
                   
                }
                i++;
                j++;
            }
            // cout<<endl;
        }
        for(int i=x;i<=y;i++) ans+=s[i];
        
       return ans;
    }
};