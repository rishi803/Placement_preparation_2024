​
```
class Solution {
public:
int mod=int(1e9+7);
int help(int idx,int mostpeo,int minpro,vector<int>&group,vector<int>&profit,vector<vector<vector<long long>>>&dp){
if(mostpeo<0) return 0;
if(idx==profit.size()){
if(minpro>0) return 0;
else return 1;
}
if(minpro<0) minpro=0;
if(dp[idx][minpro][mostpeo]!=-1) return dp[idx][minpro][mostpeo];
long long chorikrle= help(idx+1,mostpeo-group[idx],minpro-profit[idx],group,profit,dp);
long long matkr= help(idx+1,mostpeo,minpro,group,profit,dp);
return dp[idx][minpro][mostpeo]=(chorikrle+matkr)%(mod);
}
int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
vector<vector<vector<long long>>>dp(group.size(),vector<vector<long long>>(minProfit+1,vector<long long>(n+1,-1)));
return help(0,n,minProfit,group,profit,dp);
}
};
```