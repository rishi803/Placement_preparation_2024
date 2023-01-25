

class Solution {
public:
    
    void dfs(int node,vector<int>&edges,vector<int>&dist,vector<bool>&vis){
        
        vis[node]=true;
        
        int child=edges[node];
        
        if(child!=-1 and !vis[child]) 
        {
            vis[child]=true;
            dist[child]=1+dist[node];
            dfs(child,edges,dist,vis);
            
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        vector<bool>vis1(n,false),vis2(n,false);
       
        vector<int>dist1(n,INT_MAX),dist2(n,INT_MAX);
        dist1[node1]=0;
        dist2[node2]=0;
        int ans=INT_MAX,idx=-1;
        dfs(node1,edges,dist1,vis1);
        dfs(node2,edges,dist2,vis2);
        
        for(int i=0;i<n;i++){
            // cout<<dist1[i]<<" "<<dist2[i]<<endl;
            
                int mx_val=max(dist1[i],dist2[i]);
                if(ans>mx_val) {
                    ans=mx_val;
                    idx=i;}
            
        }
        return idx;
    }
};