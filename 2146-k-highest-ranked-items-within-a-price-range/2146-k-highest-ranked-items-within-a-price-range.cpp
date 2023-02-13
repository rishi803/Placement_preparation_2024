class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>>ans;
        queue<pair<int,int>>q;         // making a queue
        
        q.push({start[0],start[1]});
        vector<int>dir={-1,0,1,0,-1};
         vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size()));
        seen[start[0]][start[1]] = true;

        
        while(!q.empty() && ans.size() < k){
            
            int cnt = q.size();
            vector<vector<int>> tmp;
            
            while (cnt--) {
            
            auto [x,y]=q.front();
            q.pop();
            
             if(grid[x][y]>=pricing[0] and grid[x][y]<=pricing[1]) tmp.push_back({grid[x][y],x,y});
            
            for(int i=0;i<4;i++){
                
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                
        if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size() and grid[nx][ny]!=0 and seen[nx][ny]==0){
            seen[nx][ny]=1;
            q.push({nx,ny});
           
        }
    }
            }
             sort(begin(tmp), end(tmp));
           
            for (auto c : tmp) {
                ans.push_back({c[1], c[2]});
                if (ans.size() == k) break;
            }
}
            return ans;
        
    }
    
};