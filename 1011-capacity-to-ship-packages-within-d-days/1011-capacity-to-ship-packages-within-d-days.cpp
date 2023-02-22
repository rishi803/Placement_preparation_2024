class Solution {
public:
    bool isValid(int mid_weight,vector<int>&weights,int days){
        int cnt=1,sum=0;
        
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            
            if(sum>mid_weight){
                cnt++;
                sum=weights[i];
            }
        }
        return cnt<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=*max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);
        
        int ans=0;
        
        while(low<=high){
            
            int mid_weight= low+(high-low)/2;
            
            if(isValid(mid_weight,weights,days)){
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