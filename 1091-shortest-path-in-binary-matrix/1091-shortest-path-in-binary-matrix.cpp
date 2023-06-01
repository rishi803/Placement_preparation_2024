class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        
        queue<pair<int,int>>q;
        vector<int>dir={-1,0,1,0,-1,-1,1,1,-1};
        if(grid[0][0]==1 or grid[row-1][col-1]==1) return -1;
        
        q.push({0,0});
        int ans=0;
        
        while(!q.empty()){
               ans++;
            int sz=q.size();
            while(sz--){
                
            auto [x,y]=q.front();
            q.pop();
            grid[x][y]=1;
                
            if(x==row-1 and y==col-1) return ans;
            
            for(int i=0;i<8;i++){
                int newx=x+dir[i];
                int newy=y+dir[i+1];
                
           if(newx>=0 and newx<row and newy>=0 and newy<col and grid[newx][newy]==0){
                   q.push({newx,newy}); 
                   grid[newx][newy]=1;
             }
           }
       }
        
            
        }
        return -1;
    }
};