class Solution {
public:
    int minNumberOfHours(int inen, int inex, vector<int>& en, vector<int>& ex) {
        int ans=0;
        
        for(int i=0;i<en.size();i++){
            
            if(inen<=en[i]){
                int req=(en[i]-inen+1);
                ans+=req;
                inen+=req;
            
            }
            if(inex<=ex[i]){
                int req=(ex[i]-inex+1);
                ans+=req;
                inex+=req;
            }
            
            inen-=en[i];
            inex+=ex[i];
        }
        
        return ans;
    }
};