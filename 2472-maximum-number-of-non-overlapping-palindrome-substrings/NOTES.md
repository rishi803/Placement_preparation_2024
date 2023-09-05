```
class Solution {
public:
int dp[2001];
bool ispalin(string &s, int st, int end){
// cout<<st<<" "<<end;
while(st <= end){
// cout<<s[st];
if(s[st++] != s[end--]) return false;
}
// cout<<endl;
return true;
}
int help(string &s, int k, int idx){
if(idx >= s.size()) return 0;
if(dp[idx] != -1) return dp[idx];
int ans= INT_MIN;
for(int i= idx; i<s.size(); i++){
if( (i-idx+1) >= k and ispalin(s, idx, i)){
ans= max(ans, 1+help(s, k, i+1));
}
else{
ans= max(ans, help(s,k,i+1));
}
}
return dp[idx]= ans;
}
int maxPalindromes(string s, int k) {
memset(dp, -1, sizeof(dp));
return help(s, k, 0);
}
};
```