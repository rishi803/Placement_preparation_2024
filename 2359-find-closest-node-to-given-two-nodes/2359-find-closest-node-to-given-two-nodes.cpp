/////////////////////////////////////// RULES FOR A BETTER PROGRAMMER ///////////////////////////////////////////////////////

// 1. Should know all approaches to solve a particular problem ( atleast standared approaches should known by you)
// 2. Use variable name familiar with task you r performing so that anyone can undertand your code just by looking + comment each line if necessary 
// 3. Hurray!!!! You will surely going to nailed the problem solving.

class Solution {
public:
    
    void dfs(int node,vector<int>&edges,vector<int>&dist,vector<bool>&vis){
        
        vis[node]=true;          // now this node is visited
        
        int child=edges[node];   // we skip loop beacuse each node has atmost one outgoing edge only
        
        if(child!=-1 and !vis[child])  // check whether we can go further (whether node is already visited we are going to explore and whether its termination point i.e -1)
        {
            vis[child]=true;               // can skip too because it will again marked true in dfs starting
            dist[child]=1+dist[node];     // increase distance by 1 from last node dist
            dfs(child,edges,dist,vis);    // call recursion to explore next child node of this current node
            
        }
    }
    
    void bfs(int node,vector<int>&edges,vector<int>&dist){
        
        queue<int>q;
        q.push(node);
       vector<bool>vis(edges.size(),false);
        
        while(!q.empty()){
             int node=q.front();
             q.pop();
             vis[node]=true;
             int child=edges[node];
            
             if(child!=-1 and !vis[child])  // check whether we can go further (whether node is already visited we are going to explore and whether its termination point i.e -1)
        {
            vis[child]=true;               // can skip too because it will again marked true in dfs starting
            dist[child]=1+dist[node];     // increase distance by 1 from last node dist
            q.push(child);   // call recursion to explore next child node of this current node
            
        }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n=edges.size();
        vector<bool>vis1(n,false),vis2(n,false);
        vector<int>dist1(n,-1),dist2(n,-1);
        
        dist1[node1]=0;
        dist2[node2]=0;
        int ans_min_dist=INT_MAX,ans_min_dist_node=-1;  //(you can initialise with any value not necessary to -1 beacuse it will update for sure)
        
        // dfs(node1,edges,dist1,vis1);
        // dfs(node2,edges,dist2,vis2);
        
        bfs(node1,edges,dist1);
        bfs(node2,edges,dist2);
        
        for(int i=0;i<n;i++){
            // cout<<dist1[i]<<" "<<dist2[i]<<endl;
            
            // Below condition are fully customizable according to your need --> i have written my own
            
            if(dist1[i]!=-1 and dist2[i]!=-1){      // if same node is updated by both node then only it means that this node is visited by both node so now find max distance value 
                
                int mx_dist_val=max(dist1[i],dist2[i]);  // max(dist(node1-->thisNode),dist(node2-->thisNode))
                if(ans_min_dist>mx_dist_val) { // minimize this max_dist_val
                    ans_min_dist=mx_dist_val;
                    ans_min_dist_node=i;}
            }
        }
        return ans_min_dist_node;        // return node value not the dist value.
    }
};