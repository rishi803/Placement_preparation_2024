class Solution {
public:
    
    bool isvalid(int banana, vector<int>&piles, int hour){
        
        int cnt= 0;
        
        for(int i=0; i<piles.size(); i++)
        {
            if(piles[i] > banana){
                cnt+= piles[i]/banana;
                if(piles[i] % banana != 0) cnt++;
            }
            else cnt++;
        }
        
        return cnt<=hour;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long low= 1;        // sabse best condition me
        long long high= accumulate(piles.begin(), piles.end(),0ll);   // sabse worst condition me
        
        int ans= -1;
        
        while(low <= high){
            long long mid_can= low + (high-low)/2;
            
            if(isvalid(mid_can, piles, h)){
                ans= mid_can;
                high= mid_can-1;                      // minimize the maximum answer
            }
            
            else{
                low= mid_can+1;
            }
        }
       
        return ans;
    }
};