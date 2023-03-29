class Solution {
public:
    
   
    int minElements(vector<int>& nums, int limit, int goal) {
        
       
        long long sum=0;
        
        for(auto i:nums) sum+=i;
        
        if(sum==goal) return 0;
         long long req=goal-sum;
         
        
        if(abs(req)<=limit) return 1;
      
        
        else{
            req=abs(req);
            return ((req-1)/limit)+1;
        }
        return -1;
    }
};