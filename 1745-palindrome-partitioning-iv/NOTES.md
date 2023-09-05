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
}
bool checkPartitioning(string s) {
memset(paldp, -1, sizeof(paldp));
memset(dp, -1, sizeof(dp));
return help(s, 0, 3);
}
};
```