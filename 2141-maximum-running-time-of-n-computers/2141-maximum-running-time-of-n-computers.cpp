class Solution {
public:
    
    bool isValid(long long min,vector<int>&batteries,int n){
        long long sum=0;
        
        for(int i=0;i<batteries.size();i++){
            sum+=batteries[i];
            if(sum>=min){
                n--;
                sum-=min;
            }
            
        }
        if(n<=0) return true;
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long low=1;
       sort(batteries.begin(),batteries.end());
        long long high= accumulate(batteries.begin(),batteries.end(),0ll);
        high/=n;
        long long ans=0;
        
        while(low<=high){
            
            long long mid=low+(high-low)/2;
            
            if(isValid(mid,batteries,n)){
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