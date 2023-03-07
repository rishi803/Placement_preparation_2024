// First please understand the problem



class Solution {
public:
    
    bool isValid(vector<int>&dist,double hour,int speed){
        
        double res=0;
        
        for(int i=0;i<dist.size();i++){
            
            double temp=double(dist[i])/double(speed);  // find the hour for ith train
           
            
            
            if(i<dist.size()-1){  // har train ek integer val par depart hogi isliye agar temp ki value decimal me h to usko next integer me convert kro sivay last train ke
                if(ceil(temp)>hour) return false;  // agar yhi val hour se bdi hui to problem h (can skip also)
                 res+=(ceil(temp));  
            }
           
            
            else res+=temp;  // agar last element h to uska ceil val nhi lenge kunki vo last train h
        }
        
        return res<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
      int low=1;
      int high=1e7;
        
        int ans=-1;
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
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