class Solution {
public:
    
    long long dp[100002];
    long long help(vector<vector<int>>&questions,int idx){
     
        if(idx>=questions.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        long long solve=0,skip=0;
        
        skip=help(questions,idx+1);
        solve=questions[idx][0]+help(questions,idx+questions[idx][1]+1);
           
        return dp[idx]=max(skip,solve);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        
        memset(dp,-1,sizeof(dp));
        return help(questions,0);
    }
};