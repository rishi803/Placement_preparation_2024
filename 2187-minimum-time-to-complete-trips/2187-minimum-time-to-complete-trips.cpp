class Solution {
public:
    
    bool isValid(long long mid,vector<int>&time,int trips){
        
        long long total=0;
        
        for(int i=0;i<time.size();i++){
            total+=(mid/time[i]);
        }
        return total>=trips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=0;
    
        long long low= *min_element(time.begin(),time.end());
        long long high= 1e14;
        
        while(low<=high){
            long long mid=low+(high-low)/2;
            
            if(isValid(mid,time,totalTrips)){
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