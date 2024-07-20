// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1



// 0----> {1,100}                 
// 1----> {2,100} {3,600}
// 2----> {0,100} {3,200}

// idx =    0          1          2          3             (initially)
// cost=    0        INT_MAX    INT_MAX    INT_MAX



/*
queue =  [  [{0,0}] ] 
stops =        0     
    
idx =    0          1          2          3           (for node 0 update node 1 and also update minCost) 
cost=    0         100   INT_MAX    INT_MAX
    
*/
/*

queue =  [ [{1,100}] ]                              (for node 1 update node 2 and node 3 and also update minCost)
stops =        1
    
idx =    0          1          2          3            
cost=    0          100       200        700
    
*/
/*
    
queue =  [  [{2,200}  {3,700}]  ]     (return mn_cost because we have used total stops)
stops =         2        2

*/



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);       // vector<vector<dest,cost>>
        for(auto e : flights) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        int ans=INT_MAX;
        vector<int> cost(n, INT_MAX);
        cost[src]=0;
        queue<pair<int, int>> q;                       
        q.push({src, 0});                      // q<pair<dest,initial_cost>>
        
        int stops= 0;
        
        while(!q.empty() and stops <= k){
            
            int sz= q.size();
            
            while(sz--){
                
                int cur_node= q.front().first;
                int abhi_tak_cost= q.front().second;
                q.pop();
                
                for(auto &child : graph[cur_node]){
                    if(cost[child.first] < abhi_tak_cost + child.second) continue;  // agar is node par phle se koi choti cost ka rasta tha to aj isse jyada cost se kun jaye vapas lauto
                    
                    if(child.first == dst) ans= min(ans, abhi_tak_cost + child.second); // answer utha lo agar destination yhi h isse age vaise bhi nhi jana 
                    
                    else{
                        cost[child.first]= abhi_tak_cost + child.second;
                        q.push({child.first, abhi_tak_cost + child.second});
                    }
                    
                    
                }
                
            }
            
            stops++;
                
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};