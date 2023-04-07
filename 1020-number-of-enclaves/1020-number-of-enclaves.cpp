// easier one (call dfs/bfs from boundary where there is 1 in 4 direction having 1)

class Solution {
public:
    
    void help(int row,int col,int i,int j,vector<vector<int>>&grid){
        
//         queue<pair<int,int>>q;
//         vector<int>dir={-1,0,1,0,-1};
//         q.push({i,j});
        
//         while(!q.empty()){
//             auto [x,y]=q.front();
//             q.pop();
//             grid[x][y]=0;
            
//             for(int k=0;k<4;k++){
//                 int newx=x+dir[k];
//                 int newy=y+dir[k+1];
                
//                 if(newx<row and newy<col and newx>=0 and newy>=0 and grid[newx][newy]==1){
//                     grid[newx][newy]=0;
//                     q.push({newx,newy});
//                 }
//             }
//         }
        
         if(i>=row or j>=col or i<0 or j<0 or grid[i][j]==0) return ;
        
        grid[i][j]=0;
        
        help(row,col,i+1,j,grid);
        help(row,col,i,j+1,grid);
        help(row,col,i-1,j,grid);
        help(row,col,i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<col;j++){
                
                if(j==0 or i==0 or j==col-1 or i==row-1){
                     if(grid[i][j]==1){
                         // cout<<i<<j<<endl;
                         help(row,col,i,j,grid);
                     }
                }
            }
        }
        int cnt=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<col;j++){
                
                if(grid[i][j]==1) cnt++;
            }
        }
        
        return cnt;
    }
};