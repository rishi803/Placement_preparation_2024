//     s1= great      s2=  rgeat
//     if(notswap) check isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i,n-i),s2.substr(i,n-i)); i.e ("gr" of s1,"rg" of s2)  and ("eat" of s1,"eat" of s2)
        
//     if(swapped)  check isScramble(s1.substr(0,i),s2.substr(n-i,i)) and isScramble(s1.substr(i,n-i),s2.substr(0,n-i));  i.e ("gr" of s1, "at" of s2) and ("eat" of s1,"rge" of s2)

// above example is considered for i=2

class Solution {
public:
    
    unordered_map<string,bool>mp;
    
    
    bool isScramble(string s1, string s2) {
        
        if(s1==s2) return true;
        if(s1.size()!=s2.size()) return false;   // if size of both string not equal it will never scrambled
        
        string key=s1+" "+s2;          // to distinguish (ex- great with gr|eat as gr_eat(x+y) and eat_gr(y+x))
        if(mp.find(key)!=mp.end()) return mp[key];
        
        
        bool notswap=false,swapped=false;
        int n=s1.size();
        
        for(int i=1;i<n;i++){
            
            notswap= isScramble(s1.substr(0,i),s2.substr(0,i)) and isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
            
            if(notswap) return true;     // agar bina swap kiye hi s1 aur s2 match kr gaya
            
            swapped= isScramble(s1.substr(i,n-i),s2.substr(0,n-i)) and isScramble(s1.substr(0,i),s2.substr(n-i,i));
            
            if(swapped) return true;     // agar swap (y+x) krne pr s1 aur s2 match kr gaye
            
             
        }
        
       
        
        return mp[key]=false;       // store that they can not be equal for this particular string
    }
};