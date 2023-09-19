class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans= 0;
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                
                ans= max(ans, dp[i][j]);
            }
            // cout<<endl;
        }
        
        return ans*ans;
    }
};