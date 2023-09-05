**Make partition-1 since last part is **
```
class Solution {
public:
int sz;
vector<vector<int>>dp;
bool ispalin(string &s, int st, int end){
while(st<=end){
if(s[st++]!=s[end--]) return false;
}
return true;
}
bool help(string &s,int idx,int partition){
if(idx>=s.size()) return partition==0;
if(dp[idx][partition]!=-1) return dp[idx][partition];
if(partition==0) return ispalin(s,idx,sz-1);
bool ans=false;
for(int i=idx;i<sz-1;i++){   // why sz-1 and partition=2 because it make sure that partition become 0 it means we have make 2 cuts surely and there must be some remaining string which is palindrome
if(ispalin(s,idx,i)){
ans|= help(s,i+1,partition-1);
}
}
return dp[idx][partition]=ans;
}
bool checkPartitioning(string s) {
dp.resize(s.size(),vector<int>(3,-1));
sz=s.size();
return help(s,0,2);
}
};