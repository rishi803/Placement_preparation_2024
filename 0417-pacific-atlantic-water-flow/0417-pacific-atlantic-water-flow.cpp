class Solution {
public:
    vector<int> dx {0, -1, 0, 1, 0};        // for storing direction ((0,-1) (-1,0) (0,1) (1,0))
    
//     void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int x, int y){
//         if(visited[x][y]) return;
//         visited[x][y] = true;
// 		// if cell reachable from both the oceans, insert into final answer vector
//         if(atlantic[x][y] && pacific[x][y]) ans.push_back(vector<int>{x, y});  
         
//         int m = mat.size(), n = mat[0].size();
//         for(int i=0; i<4; i++){
//             int nx = x+dx[i], ny = y+dx[i+1];
//             if(nx<0 || nx>=m || ny<0 || ny>=n || mat[nx][ny] < mat[x][y]) continue;
            
//             dfs(mat,visited,nx,ny);
//         }
//     }
     void bfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
         
        q.push({i, j});
        while(!q.empty()){
            auto[i, j] = q.front(); q.pop();
            if(visited[i][j]) continue;
            visited[i][j] = true;
            if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
             int m = mat.size(), n = mat[0].size();
            for(int x=0; x<4; x++){
            int nx = i+dx[x], ny = j+dx[x+1];
            if(nx>=0 and nx<m and ny>=0 and ny<n and mat[nx][ny] >= mat[i][j]) q.push({nx,ny});
        }
        }
    }
     int m, n;
    queue<pair<int, int> > q;
	// denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<bool> > atlantic, pacific; 
	vector<vector<int> > ans;    
    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
        
        if(!size(mat)) return ans;
        m = size(mat), n = size(mat[0]);
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
		// perform dfs from all edge cells (ocean-connected cells)
        for(int i = 0; i < m; i++) bfs(mat, pacific, i, 0), bfs(mat, atlantic, i, n - 1);
        for(int i = 0; i < n; i++) bfs(mat, pacific, 0, i), bfs(mat, atlantic, m - 1, i);             
        return ans;
    }
};