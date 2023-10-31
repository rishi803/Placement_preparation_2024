class Solution {
public:
    
    bool isvalid(vector<int>&nums, int speed, int given_hour){
        
        long long hour= 0;
        
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i] >= speed){
                int current_time= (nums[i] / speed);
                
                if((nums[i] % speed) != 0)
                current_time ++;
                
                hour= hour + current_time;
            }
            
            else{
                hour++;
            }
        }
        return hour <= given_hour;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
      
        int low= 1;
        long long high= 1e9;
        
       
        
        int ans= 0;
        
        while(low <= high){
            int midspeed= low+(high-low)/2;
            
            if(isvalid(piles,midspeed, h)){
                ans= midspeed;
                high= midspeed-1;
            }
            else{
                low= midspeed+1;
            }
        }
        
        return ans;
    }
};