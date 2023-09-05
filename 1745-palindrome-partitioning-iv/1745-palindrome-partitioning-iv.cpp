class Solution {
public:
    
    vector<vector<int>>dp;
    int paldp[2001][2001];
    
    bool ispalin(string &s, int i, int j){
        
        if(i>=j) return paldp[i][j] = true;
        if(paldp[i][j]!=-1) return paldp[i][j];
        if(s[i]!=s[j]) return paldp[i][j] = false;
        return paldp[i][j] = ispalin(s, i+1, j-1);
    }
    
    int help(string &s, int idx, int cut){
        if(idx >= s.size()) return 0;
        if(cut==0) return ispalin(s, idx, s.size()-1);
        if(dp[idx][cut] != -1) return dp[idx][cut];
        
        bool ans= false;
        
        for(int i= idx; i<s.size(); i++){
            
            if(ispalin(s, idx, i)){
                ans= ans or help(s, i+1, cut-1);
            }
        }
        
        return dp[idx][cut]= ans;
    }
    
    bool checkPartitioning(string s) {
        
        dp.resize(s.size(), vector<int>(3,-1));
        memset(paldp, -1, sizeof(paldp));
        return help(s, 0, 2);
    }
};