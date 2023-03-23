class Solution {
public:
    
    bool isvalid(long long time,vector<int>&ranks,int cars){
        
        long long cars_repaired=0;
        
        for(int i=0;i<ranks.size();i++){
            
            cars_repaired+=sqrt(time/ranks[i]);
        }
        
        return cars_repaired>=cars;
        
    }
    long long repairCars(vector<int>& ranks, int cars) {
        
        long long low= *min_element(ranks.begin(),ranks.end());
        long long high=1e14;
        
        long long ans=0;
       
        
        while(low<=high){
           long long mid=low+(high-low)/2;
            
            if(isvalid(mid,ranks,cars)) {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};