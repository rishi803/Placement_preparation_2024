class Solution {
public:
    int maxJump(vector<int>& stones) {
       
        // int res=0;
        // for(int i = 3; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // odd path
        // for(int i = 2; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // even path
        // return res;
        
        if(stones.size()==2) return stones[1]-stones[0];
        
         int ans=0;
        
        for(int i=2;i<stones.size();i++){
            ans=max(ans,stones[i]-stones[i-2]);           
        }
        
        return ans;
    }
};