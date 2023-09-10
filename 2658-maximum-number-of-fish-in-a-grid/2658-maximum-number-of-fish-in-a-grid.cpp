class Solution {
public:
    
    vector<int>dir= {-1,0,1,0,-1};
    int ans= 0;
    
    void help(vector<vector<int>>&grid, int i, int j, int &fish){
           
        
           queue<pair<int,int>>q;
            q.push({i,j});
        
        while(!q.empty()){
            auto [i,j]= q.front();
            q.pop();
            
             fish+= grid[i][j];
              grid[i][j]= 0;
            
             for(auto it=0; it<4; it++){
            int x= i+ dir[it];
            int y= j+ dir[it+1];
            
             if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y] == 0) continue;
                 else
            q.push({x,y});
        }
        }
        
             
        
       
        
        
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] > 0){
                    
                    int fish= 0;
                    help(grid, i, j, fish);
                    
                    ans= max(ans, fish);
                }
            }
        }
        
        return ans;
    }
};