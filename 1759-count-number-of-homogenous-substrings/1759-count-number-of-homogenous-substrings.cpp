class Solution {
public:
    const int mod= int(1e9+7);
    
    int countHomogenous(string s) {
        
        int sz=s.size();
        
        long long ans=0,head=0,tail=0;
        
        for(head=1;head<s.size();head++){
            
            if(s[head]!=s[head-1]){
                tail=head;
            }
            ans+=(head-tail)%(mod);
        }
        
        return (ans+sz)%(mod);
    }
};