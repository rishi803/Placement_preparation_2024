class Solution {
public:
    vector<int> countBits(int n) {
        
        if(n == 0) return {0};
        if(n == 1) return {0,1};
        if(n == 2) return {0,1,1};
        
        vector<int>ans(n+1);
        ans[0]= 0;
        ans[1]= 1;
        ans[2]= 1;
        
        int pow2= 2;
        
        for(int i=3; i<=n; i++){
            
            
            if(i % pow2 == 0){
                pow2= i, ans[i]= 1;
            } 
            
            else{
               int idx= i % pow2;
               ans[i]= 1+ans[idx];
            }
        }
        
        return ans;
    }
};