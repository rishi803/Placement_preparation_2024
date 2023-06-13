class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int ans=0;
        map<vector<int>,int>ump;
        
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            for(int j=0;j<grid[0].size();j++){
            temp.push_back(grid[i][j]);
     }
        ump[temp]++;
  }
        
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[j][i]);
            }
            if(ump[temp]>0){
                ans+=ump[temp];
            }
        }
        return ans;
    }
};