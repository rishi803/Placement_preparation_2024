int minimumPartition(string s, int k) {
long long  cur=0,ans=1;
for(int i=0;i<s.size();i++){
int num=s[i]-'0';
if(cur>k) return -1;
cur=cur*10+num;
if(cur>k){
cur/=10;
if(cur==0) return -1;
ans++;
cur=num;
}
}
return ans;
}