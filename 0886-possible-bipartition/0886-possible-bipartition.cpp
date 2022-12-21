class Solution {
public:
    vector<int>parent;
    
    int find(int x){
        if(x!=parent[x]) return parent[x]=find(parent[x]);
        return x;
        
    }
    void unite(int x,int y){
        int absrootx=find(x);
        int absrooty=find(y);
        
       parent[absrootx]=absrooty;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        
        unordered_map<int,vector<int>> adjMap;
        
        for(auto &d : dislikes){
            adjMap[d[0]].push_back(d[1]);
            adjMap[d[1]].push_back(d[0]);
        }
        
        
        for(auto &pair : adjMap){
            auto currVec = pair.second;
            int first = currVec[0];
            for(int i=1;i<currVec.size();i++){
                unite(first,currVec[i]); 
                // making set of all disliked people by the current key
            }
        }
        
        for(auto &it:dislikes){
            if(find(it[0])==find(it[1])) return false;
        }
        return true;
        
    }
};