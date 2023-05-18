class Solution {
public:
 vector<int>parent;
    int find(int child){
        if(parent[child]==-1) return child;
        return parent[child]=find(parent[child]);
    }
    
    void combine(int first,int second){
        if(find(second)==second)
        parent[second]=first;
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        parent.resize(n,-1);
       for(auto &it:edges){
        combine(it[0],it[1]);
        }
        
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<parent[i]<<endl;
            if(parent[i]==-1) ans.push_back(i);
        }
        return ans;
   }

};