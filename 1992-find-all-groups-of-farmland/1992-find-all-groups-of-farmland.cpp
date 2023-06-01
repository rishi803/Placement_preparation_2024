class Solution {
public:
    
    void dfs(int x,int y,int row,int col,vector<vector<int>>&land,set<pair<int,int>>&temp){
        if(x<0 or x>=row or y<0 or y>=col or land[x][y]==0) return;
        
        land[x][y]=0;
        temp.insert({x,y});
        
        dfs(x+1,y,row,col,land,temp);
        dfs(x,y+1,row,col,land,temp);
        dfs(x-1,y,row,col,land,temp);
        dfs(x,y-1,row,col,land,temp);
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row=land.size();
        int col=land[0].size();
        vector<vector<int>>ans;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(land[i][j]==1){
                    set<pair<int,int>>temp;
                    dfs(i,j,row,col,land,temp);
                    int tlx=temp.begin()->first,tly=temp.begin()->second;
                    auto it=--temp.end();
                    int brx=it->first,bry=it->second;
                    
                    ans.push_back({tlx,tly,brx,bry});
                }
            }
        }
        
        return ans;
    }
};