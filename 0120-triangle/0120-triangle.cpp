class Solution {
public:
    
    int dp[202][202];
    
    int help(vector<vector<int>>&triangle,int i,int j){
        
        if(i>=triangle.size()) return 0;
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=1e7) return dp[i][j];
        
        
        int op1=triangle[i][j]+help(triangle,i+1,j);
        int op2=triangle[i][j]+help(triangle,i+1,j+1);
        
        return dp[i][j]=min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i=0;i<202;i++){
            for(int j=0;j<202;j++){
                dp[i][j]=1e7;
            }
        }
        return help(triangle,0,0);
    }
};