```
class SummaryRanges {
public:
vector<int>v;
int maxi=0;
SummaryRanges() {
vector<int>temp(10002,0);
v= temp;
}
void addNum(int value) {
v[value]=1;
maxi= max(maxi, value);
}
vector<vector<int>> getIntervals() {
vector<vector<int>>ans;
vector<int>temp;
for(int i=0;i<=maxi;i++)    // maxi+1 so that
{
while(v[i]==1){
temp.push_back(i);
i++;
}
if(temp.size()){
ans.push_back({temp.front(),temp.back()});
temp.clear();
}
}
return ans;
}
};
​
​
```