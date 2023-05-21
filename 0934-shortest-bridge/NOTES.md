class Solution {
public:
queue<pair<int,int>>q;
int dist=0;
// vector<vector<int>>vis;
void dfs(int row,int col,int i,int j,vector<vector<int>>&grid){
if(i>=row or i<0 or j>=col or j<0 or grid[i][j]!=1) return;
grid[i][j]=2;
q.push({i,j});
dfs(row,col,i+1,j,grid),
dfs(row,col,i,j+1,grid),                                            dfs(row,col,i,j-1,grid),
dfs(row,col,i-1,j,grid);
}
int bfs(int row,int col,vector<vector<int>>&grid){
vector<int>dir={-1,0,1,0,-1};
while(!q.empty()){
int sz=q.size();