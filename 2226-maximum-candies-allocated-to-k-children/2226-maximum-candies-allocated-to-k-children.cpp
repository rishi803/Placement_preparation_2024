class Solution {
public:
    
    
    bool isvalid(vector<int>&candies, int mid, long long k){
        long long cnt= 0;

        for(int i=0; i<candies.size(); i++){

            cnt+= candies[i]/mid;
        }
        
        return cnt>=k;
        
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long total= accumulate(candies.begin(), candies.end(),0ll);
        if((total/k) <= 0) return 0;
        
        int low=1;
        int high= *max_element(candies.begin(), candies.end());
        int ans= 0;
        
        while(low <= high){
            int mid= low + (high-low) / 2;
            
           if (isvalid(candies, mid, k)){
                ans= mid;
                low= mid+1;
            }
            
            else{
                high= mid-1;
            }
        }
        
        return ans;
        
    }
};