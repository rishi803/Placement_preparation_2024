class Solution {
public:
    
    bool help(vector<vector<int>>&graph,vector<bool>&vis,int node,vector<bool>&pathvis,int idx){
        
       
        vis[node]=true;
        pathvis[node]=true;
        
        for(auto child:graph[node]){
         if(pathvis[child]==false && help(graph,vis,child,pathvis,idx)){
                return true;
            }
            else if(vis[child]==true){
            return true;
        }
        }
        // cout<<endl;
        vis[node]=false;
        // return true;
        return false;
    
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      
        vector<bool>vis(graph.size()),pathvis(graph.size());
        vector<int>ans;
        
        for(int i=0;i<graph.size();i++){
            
           if(!vis[i]){
               
             help(graph,vis,i,pathvis,i);
           }
               
            
        }
        
        for(auto i=0;i<vis.size();i++) if(vis[i]==0) ans.push_back(i);
        return ans;
    }
};