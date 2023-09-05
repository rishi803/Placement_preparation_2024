}
return dp[idx][partition]=ans;
}
bool checkPartitioning(string s) {
dp.resize(s.size(),vector<int>(3,-1));
sz=s.size();
return help(s,0,2);
}
};
```
​
**Make all the cuts and if (cuts==0 && idx>=s.size()) return true**
```
// Exactly similar code as https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/?envType=list&envId=oc88tln3
​
class Solution {
public:
int dp[2001][4];
int paldp[2001][2001];
bool ispal(string &s, int i, int j)
{
if(i>=j) return paldp[i][j] = true;
if(paldp[i][j]!=-1) return paldp[i][j];
if(s[i]!=s[j]) return paldp[i][j] = false;
return paldp[i][j] = ispal(s, i+1, j-1);
}
int help(string &s, int idx, int cut){
if(cut == 0 and idx >= s.size()) return true;
if(cut < 0 or idx >= s.size()) return false;
if( dp[idx][cut] != -1) return dp[idx][cut];
bool ans= false;
for(int i= idx; i<s.size(); i++){
if( ispal (s, idx, i) ){
ans= ans | (help(s, i+1, cut-1));
}
}
return dp[idx][cut]= ans;