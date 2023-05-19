class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color(graph.size());
        queue<int>q;
        
        for(int i=0;i<graph.size();i++){
            
            if(color[i]!=0) continue;
            color[i]=1;
            q.push(i);
            
            while(!q.empty()){
                int cur=q.front();
                q.pop();
                // cout<<cur<<" "<<color[cur]<<endl;
            for(auto node:graph[cur]){
               if(color[node]==color[cur]) return false;
                if(color[node]) continue;
                if(color[cur]==1)
                color[node]=2,q.push(node);
                else if(color[cur]==2) color[node]=1,q.push(node);
                
            }
        }
    } 
        return true;
    }
};