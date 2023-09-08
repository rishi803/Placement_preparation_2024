class Solution {
public:
    
    int ans= INT_MAX;
    // int res= INT_MAX;
    int temp= INT_MAX;
    vector<vector<int>>dp;
    
    int help(vector<vector<int>>&mat, int target, int x,  int sum){
        
        if(x >= mat.size()){
         
            return abs(target-sum);
        }
        
        if(dp[x][sum] != -1) return dp[x][sum];
        
        
        int res= INT_MAX;
        
        for(int y= 0; y<mat[x].size(); y++){
            res= min(res, help(mat, target, x+1, sum+mat[x][y]));
        }
        // cout<<endl;
        
        return dp[x][sum]= res;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        dp.resize(mat.size(), vector<int>(5000,-1));
          
      
          return help(mat, target, 0, 0);
 
    }
};