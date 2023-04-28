class Solution {
public:
    
    vector<int>parent;
    int sz=0;
    
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]=find(parent[node]);
    }
    
    void _union(int x,int y){
        int absx=find(x);
        int absy=find(y);
        
        if(absx!=absy) {
            parent[absx]=absy;
            sz--;
        }
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        parent.resize(strs.size());
        iota(begin(parent),end(parent),0);
        sz=strs.size();
        
        // sort(strs.begin(),strs.end());
        
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs.size();j++){
                int cnt=0;
                for(int k=0;k<strs[i].size();k++){
                    if(strs[i][k]!=strs[j][k]) cnt++;
                }
                // cout<<cnt<<" "<<strs[i]<<" "<<strs[j]<<endl;
                if(cnt==2 or cnt==0) _union(i,j);
            }
        }
        
       
        
        return sz;
        
    }
};