class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>in(n);
        for(auto edge:edges){
            in[edge[1]]++;
        }
        vector<int>ans;
        
        for(auto i=0;i<n;i++){
            if(in[i]==0) ans.push_back(i);
        }
        return ans;
    }
};