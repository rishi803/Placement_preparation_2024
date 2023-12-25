class Solution {
public:
    
    bool isvalid(int midbanana, vector<int>&piles, int h){
        
        int cnt= 0;
        
        for(int i=0; i<piles.size(); i++){
            
            if(piles[i] > midbanana){
                int times= piles[i]/ midbanana;
                if(piles[i] % midbanana != 0) times++;
                
                cnt= cnt + times;
            }
            
            else{
                cnt= cnt + 1;
            }
            
            
        }
        
        return cnt<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long low=   1;                // sabse best scenario
        long long high= accumulate(piles.begin(), piles.end(),0ll);               // sabse wordst scenario
        int ans= 0;
        
        while(low<=high){
            
            long long mid= low + (high-low)/2;
            
            if(isvalid(mid, piles, h)){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        
        return ans;
    }
};