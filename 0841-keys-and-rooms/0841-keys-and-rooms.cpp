class Solution {
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       
    vector<int>visited(rooms.size(),0);
    queue<int>q;
        q.push(0);
       
        
        while(!q.empty()){
            int f=q.front();q.pop();
             visited[f]=1;
            for(auto &it:rooms[f]){
                if(!visited[it]) q.push(it);
            }
        }
        if(count(visited.begin(),visited.end(),1)==rooms.size()) return true;
        return false;
        
    }
};