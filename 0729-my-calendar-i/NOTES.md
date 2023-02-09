// cout<<"St = "<<start<<" End = "<<end<<" ";
auto it=mp.upperr_bound(start);
if(it!=mp.end() and it->second<end) {
// cout<<"ubf "<<it->first<<" ";
return false;}
// else if(it!=mp.end()) cout<<"ub "<<it->first<<" ";
mp[end]=start;
// for(auto &it:mp){
//     cout<<it.first<<" "<<it.second<<endl;
// }
return true;
}
```
**Sweep Line**
```
bool book(int start, int end) {
mp[start]++;
mp[end]--;
int cnt=0;
for(auto &it:mp){
cnt+=it.second;
if(cnt>1){
mp[start]--;
mp[end]++;
return false;
}
}
return true;
}
```
​