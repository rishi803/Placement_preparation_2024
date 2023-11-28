class Solution {
public:
    int mod = 1000000007;
    
    long help(int n, int i, int j, vector<vector<vector<int>>>& memo){
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        if(n == 1) return 1;
        if(memo[i][j][n] != -1) return memo[i][j][n];
        
        long ans = (
            help(n - 1, i - 1, j - 2, memo) % mod + 
            help(n - 1, i - 2, j - 1, memo) % mod + 
            help(n - 1, i - 2, j + 1, memo) % mod + 
            help(n - 1, i - 1, j + 2, memo) % mod + 
            help(n - 1, i + 1, j + 2, memo) % mod + 
            help(n - 1, i + 2, j + 1, memo) % mod + 
            help(n - 1, i + 2, j - 1, memo) % mod + 
            help(n - 1, i + 1, j - 2, memo) % mod
        ) % mod;
        
        return memo[i][j][n] = ans;
    }
    
    int knightDialer(int n) {
        vector<vector<vector<int>>> memo(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        long s = 0;
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                s = (s + help(n, i, j, memo)) % mod;
            }
        }
        
        return (int) s;
    }
};
