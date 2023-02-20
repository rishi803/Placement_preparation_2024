```
int maxDistToClosest(vector<int>& seats) {
vector<int>temp;
for(int i=0;i<seats.size();i++){
if(seats[i]==1) temp.push_back(i);
}
int mx=1,mn=INT_MAX;
for(int i=0;i<seats.size();i++){
mn=INT_MAX;
if(seats[i]==0){
for(int j=0;j<temp.size();j++){
mn=min(mn,abs(i-temp[j]));
// cout<<mn<<endl;
}
// cout<<endl;
mx=max(mx,mn);
}
}
return mx;
}
```