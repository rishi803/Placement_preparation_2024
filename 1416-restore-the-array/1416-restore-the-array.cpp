class Solution {
public:
    
    int dp[100002];
    int help(string &s,int k,int idx){
    
        
        if(idx==s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int ways=0;
        long temp;
        for(int i=idx;i<s.size();i++){
            
             temp=stol(s.substr(idx,i-idx+1));   // or temp=temp*10+(s[idx]-'0');           
            if(temp>k) break;
            ways=(ways+help(s,k,i+1))%(int(1e9+7));
        }
        
        return dp[idx]=ways;
    }
    
    int numberOfArrays(string s, int k) {
        
        memset(dp,-1,sizeof(dp));
        return help(s,k,0);
    }
};