class Solution {
public:
    vector<int>visited;
       vector<int>adj[1001];
    void help(int node){
        if(visited[node]==1) return ;
        visited[node]=1;
        for(auto &it:adj[node]){
            help(it);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        visited.resize(rooms.size(),0);
        help(0);
        if(count(visited.begin(),visited.end(),1)==rooms.size()) return true;
        else return false;
        
    }
};