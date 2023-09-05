class Solution {
public:
    
    
    bool ispalin(string &s, int st, int end){
        
        while(st <= end){
            if(s[st++] != s[end--]) return false;
        }
        
        return true;
    }
    
    int help(string &s, int idx, int cut){
        if(idx >= s.size()) return 0;
        if(cut==0) return ispalin(s, idx, s.size()-1);
        
        bool ans= false;
        
        for(int i= idx; i<s.size(); i++){
            
            if(ispalin(s, idx, i)){
                ans= ans or help(s, i+1, cut-1);
            }
        }
        
        return ans;
    }
    
    bool checkPartitioning(string s) {
        
        return help(s, 0, 2);
    }
};