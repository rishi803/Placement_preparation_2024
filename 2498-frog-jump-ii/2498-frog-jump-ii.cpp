// already sorted so find max of odd path and even path elements

class Solution {
public:
    int maxJump(vector<int>& stones) {
       
        // int res=0;
        // for(int i = 3; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // odd path
        // for(int i = 2; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // even path
        // return res;
        
        if(stones.size()==2) return stones[1]-stones[0];   // 0 3
        
         int ans=0;
        
        for(int i=2;i<stones.size();i++){    // 0 2 5 6 7  so==>(0,5,7) and (6,2)
            ans=max(ans,stones[i]-stones[i-2]);           
        }
        
        return ans;
    }
};