class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        unordered_set<int>s;
        vector<int>visited(rooms.size(),0);
        q.push(0);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            s.insert(x);
            for(auto k:rooms[x])
            {
                if(s.find(k)==s.end())
                {
                    q.push(k);
                }
            }
           
            
        }
         return rooms.size() == s.size();
         
    }
};