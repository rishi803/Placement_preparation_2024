// First please understand the problem



class Solution {
public:
    
    bool isValid(vector<int>&dist,double hour,long long speed){
        
        double res=0;
        
        for(int i=0;i<dist.size();i++){
            
            double temp=double(dist[i])/double(speed);
           
            
            
            if(i<dist.size()-1){  // har train ek integer val par depart hogi isliye agar temp ki value decimal me h to usko next integer me convert kro sivay last train ke
                // if(ceil(temp)>hour) return false;  // agar yhi val hour se bdi hui to problem h
                 res+=(ceil(temp));  
            }
           
            
            else res+=temp;  // agar last element h to uska ceil val nhi lenge kunki vo last train h
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