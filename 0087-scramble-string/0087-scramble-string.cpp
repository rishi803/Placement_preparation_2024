class Solution {
public:
    
    unordered_map<string,bool>mp;
    
    
    bool isScramble(string s1, string s2) {
        
        if(s1==s2) return true;
        if(s1.size()!=s2.size()) return false;
        
        string key=s1+" "+s2;
        if(mp.find(key)!=mp.end()) return mp[key];
        
        
        bool isswap=false,swapped=false,result=false;
        int n=s1.size();
        
        for(int i=1;i<n;i++){
            
            isswap= isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
            
            swapped= isScramble(s1.substr(i,n-i),s2.substr(0,n-i)) and isScramble(s1.substr(0,i),s2.substr(n-i,i));
            
             if(isswap or swapped) {
            result=true;
        }
        }
        
       
        
        return mp[key]=result;
    }
};