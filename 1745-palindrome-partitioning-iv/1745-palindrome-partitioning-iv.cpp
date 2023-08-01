class Solution {
public:
    
    int sz;
    
    bool ispalin(string &s, int st, int end){
        while(st<=end){
            if(s[st++]!=s[end--]) return false;
        }
        return true;
    }
    
    bool help(string &s,int idx,int partition){
        if(idx>=s.size()) return partition==0;
        
        if(partition==0) return ispalin(s,idx,sz-1);
        
        bool ans=false;
        
        for(int i=idx;i<sz-1;i++){
            if(ispalin(s,idx,i)){
                ans|= help(s,i+1,partition-1);
            }
        }
        
        return ans;
    }
    
    bool checkPartitioning(string s) {
        
        sz=s.size();
        return help(s,0,2);
    }
};