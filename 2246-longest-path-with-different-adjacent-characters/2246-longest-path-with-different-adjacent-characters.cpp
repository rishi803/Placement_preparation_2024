class Solution {
public:
    int ans=0;
    
    int dfs(vector<int>adj[],string &s, int node, int nodeparent){
        
        int longest=0,secondlongest=0;
        
        for(auto child:adj[node]){
            if(child==nodeparent) continue;
            
            int childlongestlength= dfs(adj,s,child,node);
            
            if(s[child]==s[node]) continue;
            
            if(secondlongest < childlongestlength){
                secondlongest= childlongestlength;
            }
            if(longest < secondlongest){
                swap(longest,secondlongest);
            }
        }
        
        ans= max({
            ans,
            longest,
            secondlongest,
            1+longest+secondlongest,
            1+longest,
            1+secondlongest
        });
        
        return max({
            1+longest,
            1+secondlongest
        });
    }
    
    int longestPath(vector<int>& parent, string s) {
        
        int sz= parent.size();
        
        vector<int>adj[sz];
        for(int i=1;i<sz;i++){
            adj[parent[i]].push_back(i);             // parent--->child
            adj[i].push_back(parent[i]);             // child ---> parent
        }
        
        dfs(adj,s,0,-1);
        return ans;
        
    }
};