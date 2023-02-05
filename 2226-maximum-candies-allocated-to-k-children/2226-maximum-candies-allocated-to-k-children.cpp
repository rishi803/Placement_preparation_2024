class Solution {
public:
    
    bool isValid(vector<int>&candy,long long k,int mid){
        
        long long cnt=0;
        
        for(int i=0;i<candy.size();i++){
            int distribute=candy[i];
            if(mid!=0)
             distribute=(candy[i]/mid);
            cnt+=distribute;
        }
        if(cnt>=k) return true;
        else return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long total=accumulate(candies.begin(),candies.end(),0ll);
        if((total/k)<=0) return 0;
        
        int low=*min_element(candies.begin(),candies.end())/k;
        int high=*max_element(candies.begin(),candies.end());
        int ans=0;
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(isValid(candies,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else{                                      

                high=mid-1;
            }
        }
        
        return ans;
        
    }
};