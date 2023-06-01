// class Solution {
// public:
    
//     void dfs(int x,int y,int row,int col,vector<vector<int>>&land,set<pair<int,int>>&temp){
//         if(x<0 or x>=row or y<0 or y>=col or land[x][y]==0) return;
        
//         land[x][y]=0;
//         temp.insert({x,y});
        
//         dfs(x+1,y,row,col,land,temp);
//         dfs(x,y+1,row,col,land,temp);
//         dfs(x-1,y,row,col,land,temp);
//         dfs(x,y-1,row,col,land,temp);
        
//     }
    
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         int row=land.size();
//         int col=land[0].size();
//         vector<vector<int>>ans;
        
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(land[i][j]==1){
//                     set<pair<int,int>>temp;
//                     dfs(i,j,row,col,land,temp);
//                     int tlx=temp.begin()->first,tly=temp.begin()->second;
//                     auto it=--temp.end();
//                     int brx=it->first,bry=it->second;
//                     ans.push_back({tlx,tly,brx,bry});
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    void dfs(int x, int y, int row, int col, vector<vector<int>>& land, vector<int>& temp) {
        if (x < 0 || x >= row || y < 0 || y >= col || land[x][y] == 0)
            return;

        land[x][y] = 0;
        temp[0] = min(temp[0], x);
        temp[1] = min(temp[1], y);
        temp[2] = max(temp[2], x);
        temp[3] = max(temp[3], y);

        dfs(x + 1, y, row, col, land, temp);
        dfs(x, y + 1, row, col, land, temp);
        dfs(x - 1, y, row, col, land, temp);
        dfs(x, y - 1, row, col, land, temp);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    vector<int> temp = { i, j, i, j };  // {tlx, tly, brx, bry}
                    dfs(i, j, row, col, land, temp);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};
