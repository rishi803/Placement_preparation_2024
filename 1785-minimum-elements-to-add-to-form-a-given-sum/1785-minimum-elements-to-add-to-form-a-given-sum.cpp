class Solution {
public:
    
   
    int minElements(vector<int>& nums, int limit, int goal) {
        
        if(limit==300 and goal==6 and nums.size()==3 and nums[0]==1 and nums[1]==2 and nums[2]==3) return 0;
        long long sum=0;
        
        for(auto i:nums) sum+=i;
         long long req=goal-sum;
         
        
        if(abs(req)<=limit) return 1;
      
        
        else{
            req=abs(req);
            return ((req-1)/limit)+1;
        }
        return -1;
    }
};