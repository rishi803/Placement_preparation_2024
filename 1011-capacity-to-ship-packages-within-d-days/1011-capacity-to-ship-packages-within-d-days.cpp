class Solution {
public:
    
   bool isValid(vector<int>&weights,int days,int mid_weight){
       
       int days_required=1;
       int sum=0;
       
       for(int i=0;i<weights.size();i++){
           
           sum+=weights[i];
           
           if(sum>mid_weight){
               days_required++;
               sum=weights[i];
           }
           
       }
       
       return days_required<=days;
       
   }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int ans=0;
        
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        
        while(low<=high){
            
            int mid_weight=low+(high-low)/2;
            
            if(isValid(weights,days,mid_weight)){
                
                ans=mid_weight;
                high=mid_weight-1;
            }
            
            else{
                
                low=mid_weight+1;
            }
            
            
        }
        
        return ans;
        
    }
};