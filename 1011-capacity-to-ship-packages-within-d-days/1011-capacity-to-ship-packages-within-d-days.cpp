class Solution {
public:
    
    bool isvalid(int mid_weight, vector<int>& weights ,int days){
        
        int cnt= 1;
        int sum= 0;
        
        for(int i=0; i<weights.size(); i++){
            
            sum= sum + weights[i];   
            
            if(sum > mid_weight) {
                cnt++;
                sum= weights[i];     // sum= 6
            }
        }
        
        return cnt <= days;
        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low= *max_element(weights.begin(), weights.end());        // best case
        int high= accumulate(weights.begin(), weights.end(), 0);   // worst case
        int ans= 0;
        
        while(low<=high){
            
            int mid_weight= low + (high-low)/2;         // w1, w2 w3 w4  w5 w6
            
            if(isvalid(mid_weight, weights, days)){
                 ans= mid_weight;
                 high= mid_weight-1;     // maximize the minimum
            }
            
            else{
                low= mid_weight+1;
            }
            
        }
        
        return ans;
    }
};