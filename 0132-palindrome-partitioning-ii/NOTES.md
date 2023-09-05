// int st= 0;
while(st <= end){
if(s[st] != s[end]) return false;
st++;
end--;
}
return true;
}
int help(string &s, int idx){
if(idx >= s.size()) return 0;
if(dp[idx] != -1) return dp[idx];
int ans=INT_MAX;
for(int i=idx; i<s.size(); i++){
// string sub= s.substr(idx, i+1);
if(ispalin(s,idx,s.size()-1)) return 0;
if(ispalin(s,idx,i)){
// cout<<sub<<endl;
ans= min(ans, 1+help(s,i+1));
}
}
return dp[idx]= ans;
}
int minCut(string s) {
memset(dp, -1, sizeof(dp));
return help(s, 0);
}
};
```