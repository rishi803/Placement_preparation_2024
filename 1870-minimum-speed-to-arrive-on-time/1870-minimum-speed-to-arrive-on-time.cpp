class Solution {
public:
    
    bool isValid(vector<int>&dist,double hour,long long speed){
        
        double res=0;
        
        for(int i=0;i<dist.size();i++){
            double temp=double(dist[i])/double(speed);
           
            
            
            if(i<dist.size()-1){
                if(ceil(temp)>hour) return false;
                 res+=(ceil(temp));
            }
           
            
            else res+=temp;
        }
        
        return res<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
      long long low=1;
      long long high=1e14;
        
        long long ans=-1;
        
        while(low<=high){
            
            long long mid=low+(high-low)/2;
            if(isValid(dist,hour,mid)){
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