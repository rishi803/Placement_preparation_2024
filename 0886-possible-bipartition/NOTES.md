```
class Solution {
public:
vector<int>parent;
int find(int x){
if(x!=parent[x]) return parent[x]=find(parent[x]);
return x;
}
void unite(int x,int y){
int absrootx=find(x);
int absrooty=find(y);
parent[absrootx]=absrooty;
}
bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
parent.resize(n+1);
iota(parent.begin(),parent.end(),0);
unordered_map<int,vector<int>> adjMap;
for(auto &d : dislikes){
adjMap[d[0]].push_back(d[1]);
adjMap[d[1]].push_back(d[0]);