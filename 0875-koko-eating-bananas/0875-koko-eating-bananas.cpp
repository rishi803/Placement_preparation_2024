class Solution {
public:
    
    bool isValid(vector<int>&piles,int h,int  speed){
        
        long hour=0;
        
        for(int i=0;i<piles.size();i++){
            
           
            hour+=ceil(double(piles[i])/speed);
        }
        // cout<<speed<<" "<<hour<<endl;
        
        return hour<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low=1,ans=-1;
        int high=*max_element(piles.begin(),piles.end());
        
        while(low<=high){
            
            int speed=low+(high-low)/2;
            
            if(isValid(piles,h,speed)){
                ans=speed;
                high=speed-1;
            }
            
            else{
                low=speed+1;
            }
        }
        
        return ans;
    }
};