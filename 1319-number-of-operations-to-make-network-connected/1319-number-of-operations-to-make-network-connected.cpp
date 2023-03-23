class Solution {
public:
    
    int extra_edges=0;
    int nodes_not_connected=-1;
    
    vector<int>parent;
    
    int find(int node){
        
        if(node==parent[node]) return node;
       
        return parent[node]=find(parent[node]);
    }
    
    void unite(int x,int y){
        
        int absx=find(x);
        int absy=find(y);
        
        if(absx==absy) extra_edges++;
        else{
            parent[absx]=absy;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        
        for(auto &i:connections){
            
            unite(i[0],i[1]);
        }
        
        for(int i=0;i<parent.size();i++){
            
            if(i==parent[i]) nodes_not_connected++;
            
        }
        
        return extra_edges>=nodes_not_connected?nodes_not_connected:-1;
    }
};