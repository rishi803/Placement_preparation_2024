class Solution {
public:
    
    bool isvalid(int mid,vector<int>&piles,int h){
        
        long hr=0;
        for(int i=0;i<piles.size();i++){
            
            int bananas=piles[i];
            if(bananas<mid){
                hr++;
            }
            else{
                hr+=(bananas/mid);
                if(mid>0 and bananas%mid!=0) hr++;
            }
        }
        if(hr<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int low=1;
        int high=1000000000;
        
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(isvalid(mid,piles,h)){  // kya vo mid banana kha skta h within h hours
                ans=mid;            // phle is mid banana ko store kr lo sayad yhi ans ho
                high=mid-1;         // agar ha to use aur kam banana offer krke dekho
            }
            
            else{
                low=mid+1;  // agr nhi to banana ka amount badhao
            }
        }
        
        return ans;
    }
};