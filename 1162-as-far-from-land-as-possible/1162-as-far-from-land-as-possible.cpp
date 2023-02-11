class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;          // q<pair<i,j>>
        int n=grid.size();
        
        vector<vector<int>>vis=grid;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});   // store all the i,j where there is initally land
            }
        }
        
        if(q.size()==0 or q.size()==n*n) return -1;
        
        vector<int>direction={-1,0,1,0,-1};
        int distance=-1;
        
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                auto [x,y]=q.front();
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nx=x+direction[i];
                    int ny=y+direction[i+1];
                    
            if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==0){
                grid[nx][ny]=1;
                q.push({nx,ny});
            }
                }
            }
            distance++;
        }
        
        return distance;
    }
};