class Solution {
public:
bool ispalin(string &s , int st, int end){
while(st<=end){
if(s[st++]!=s[end--]) return false;
}
return true;
}
int help(string &s, int idx,vector<int>&dp){
if(idx==s.size()) return -1;
if(dp[idx]!=-1) return dp[idx];
int ans=INT_MAX;
for(int i=idx;i<s.size();i++){
if(ispalin(s,idx,i)){
ans=min(ans,1+help(s,i+1,dp));
}
}
return dp[idx]= ans;
}
int minCut(string s) {
}
};