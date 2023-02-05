class Solution {
public:
    
    bool isvalid(int k,vector<int>&piles,int h){
        
        long hours = 0; // track count of hours
        for(int pile : piles){
            // performing claculation, take an example 
            // k = 4
            // pile = 10

            // pile / k => 10 / 4 = 2
            // pile % k => 2, so we need to have one more hour to eat remaining bananas left over as remainder 
            // hours = 3;
            int div = pile / k;
            hours += div;
            if(pile % k != 0) hours++; // if remainder value is not 0, we need to have an extra hour
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        
        
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