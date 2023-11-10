class Solution {
public:
    vector<int>ans;
    
    void help(map<int,vector<int>>&graph, unordered_map<int,int>&vis, int node){
        
        if(vis[node]==true) return;
        
        ans.push_back(node);
        vis[node]= true;
        
        for(auto &child:graph[node]){
            help(graph,vis,child);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int sz= adjacentPairs.size();
        int st;
    
        map<int,vector<int>>graph;
        
        for(auto i:adjacentPairs){
    
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        for(auto &[key,val] : graph){
            if(val.size() == 1){
                st= key;
                break;
            }
        }
        
        
        unordered_map<int,int>vis;
        help(graph,vis,st);
        
        return ans;
    }
};