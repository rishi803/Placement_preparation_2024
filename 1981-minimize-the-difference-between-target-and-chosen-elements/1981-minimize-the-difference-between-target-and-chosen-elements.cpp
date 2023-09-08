class Solution {
public:
    
    int ans= INT_MAX;
    // int res= INT_MAX;
    int temp= INT_MAX;
    vector<vector<int>>dp;
    
    int help(vector<vector<int>>&mat, int target, int x, int y, int sum){
        
        if(x >= mat.size()){
         
            return abs(target-sum);
        }
        
        if(dp[x][sum] != -1) return dp[x][sum];
        
        
        int res= INT_MAX;
        
        for(int i= 0; i<mat[x].size(); i++){
            res= min(res, help(mat, target, x+1, i,sum+mat[x][i]));
        }
        // cout<<endl;
        
        return dp[x][sum]= res;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        dp.resize(mat.size(), vector<int>(5000,-1));
          
        for(int j=0; j<mat[0].size(); j++){
              // cout<<mat[0][j]<<" ";
            ans= min(ans,help(mat, target, 0, j, 0));
          
        }
        
        return ans;
    }
};