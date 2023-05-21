class Solution {
public:
    queue<pair<int,int>>q;
    int dist=0;
    
    void dfs(int row,int col,int i,int j,vector<vector<int>>&grid){
       if(i>=row or i<0 or j>=col or j<0 or grid[i][j]!=1) return;
        
       grid[i][j]=2;
       q.push({i,j});
       dfs(row,col,i+1,j,grid),dfs(row,col,i,j+1,grid),dfs(row,col,i,j-1,grid),dfs(row,col,i-1,j,grid);
    }
    
    int bfs(int row,int col,int i,int j,vector<vector<int>>&grid){
        
        vector<int>dir={-1,0,1,0,-1};
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
               
                for(int idx=0;idx<4;idx++){
                    int newx=x+dir[idx];
                    int newy=y+dir[idx+1];
                    
                    if(newx<row and newx>=0 and newy<col and newy>=0  and grid[newx][newy]==1) return dist;
                    if(newx<row and newx>=0 and newy<col and newy>=0 and grid[newx][newy]==0){
                        q.push({newx,newy});
                        grid[newx][newy]=2;
                    }
                }
                
            }
            dist++;
        }
        return dist;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        bool flag=false;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    dfs(row,col,i,j,grid);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
            
           for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                  return bfs(row,col,i,j,grid);
                }
            }
        }
        
        return -1;
    }
};