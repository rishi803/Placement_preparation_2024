class Solution {
public:
    
    vector<vector<pair<int,int>>>route;
   
    vector<vector<int>>memo;
    
   long ans(int n, vector<vector<pair<int,int>>>& flights, int src, int dst, int k){
        if (k < 0) return INT_MAX; // No more stops allowed
        if(src == dst) return 0;
        if(memo[src][k] != -1) return memo[src][k];
        
long res= INT_MAX;
        for(auto &node : flights[src]){

       res= min(res, node.second + ans(n,flights,node.first,dst,k-1));
        }
        
        return memo[src][k]= res;
        
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        route.resize(n);
        memo.assign(n, vector<int>(k + 2, -1)); // Initialize memoization table
        
        for(auto &i:flights){
            route[i[0]].push_back({i[1], i[2]});
        }
      
        
        int result= ans(n, route, src, dst, k+1);
        if(result >= INT_MAX) return -1;
        return result;
    }
};