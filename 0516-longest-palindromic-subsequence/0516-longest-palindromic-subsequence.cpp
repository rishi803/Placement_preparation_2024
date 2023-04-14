class Solution {
public:
   int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        return longPalinSub(0,n-1, s,dp); 
    }
    int longPalinSub(int l, int r, string &s, vector<vector<int>>& dp) {
        if(l==r) return 1;
        if(l>r) return 0;
        if(dp[l][r]) return dp[l][r];
        return dp[l][r] = s[l]==s[r] ? 2 + longPalinSub(l+1,r-1, s,dp) : 
            max(longPalinSub(l+1,r, s,dp),longPalinSub(l,r-1, s,dp)); 
        
    }
};