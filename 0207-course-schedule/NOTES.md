```
vector<int>adj[numCourses];
vector<int>indegree(numCourses);
queue<int>q;
for(auto vec:pre){
adj[vec[1]].push_back(vec[0]);
indegree[vec[0]]++;
}
for(int i=0;i<numCourses;i++){
if(indegree[i]==0) q.push(i);
}
while(!q.empty()){
int cource=q.front();
q.pop();
for(auto adjcourse:adj[cource]){
indegree[adjcourse]--;
if(indegree[adjcourse]==0) q.push(adjcourse);
}
}
for(int i=0;i<numCourses;i++){
if(indegree[i]!=0) return false;
}
return true;
```