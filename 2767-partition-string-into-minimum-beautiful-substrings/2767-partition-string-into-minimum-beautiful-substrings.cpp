class Solution {
public:
    
    int ans=INT_MAX;
 
    
    bool check(long num){
        
        int mul5=1;
        
        for(int i=0;i<10;i++){
            if(num==mul5) return true;
            mul5*=5;
        }
        // cout<<"G";
        return false;
    }
    
    void help(string &s,int idx,int cnt){
        if(idx==s.size()){
            ans=min(ans,cnt);
            return;
        }
        if(s[idx]=='0') return;
        
        int mul5=0;
        // cout<<endl;
        for(int i=idx;i<s.size();i++){
      
            mul5<<=1;
            if(s[i]=='1') mul5|=1;
            
            if(check(mul5)){
                // cout<<mul5<<" ";
                help(s,i+1,cnt+1);
            }
        }
        
    }
    
    int minimumBeautifulSubstrings(string s) {
        
         help(s,0,0);
        return ans==INT_MAX?-1:ans;
    }
};