1. **Recursive**
​
```
class Solution {
public:
vector<int>visited;
void help(vector<vector<int>>&adj,int node){
if(visited[node]==1) return;
visited[node]=1;
for(auto &it:adj[node]){
help(adj,it);
}
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
visited.resize(rooms.size(),0);
help(rooms,0);
if(count(visited.begin(),visited.end(),1)==rooms.size()) return true;
else return false;
}
};
```