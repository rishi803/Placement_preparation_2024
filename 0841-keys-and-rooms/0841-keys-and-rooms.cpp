class Solution {
public:
    vector<int>visited;
    void help(vector<vector<int>>&adj,int node){
        if(visited[node]==1) return;
        visited[node]=1;
        for(auto &it:adj[node]){
            help(adj,it);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>>adj(rooms.size());
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        visited.resize(rooms.size(),0);
        help(adj,0);
        if(count(visited.begin(),visited.end(),1)==rooms.size()) return true;
        else return false;
        
    }
};