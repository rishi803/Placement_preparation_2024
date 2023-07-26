class Solution {
public:
    
    bool isvalid(vector<int>&dist,double hour,int midspeed){
        
        double totaltime=0;
        
        for(int i=0;i<dist.size();i++){
           double temp= double(dist[i])/midspeed;
            
            if(i!=dist.size()-1){
                // if(ceil(temp)>hour) return false;
                totaltime+=ceil(temp);
            }
            else
           totaltime+=temp;
        }
        // cout<<totaltime<<endl;
        return totaltime<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int highspeed=1e7,lowspeed=1;
        int ans=-1;
        
        while(lowspeed<=highspeed){
            int midspeed=lowspeed+(highspeed-lowspeed)/2;
           
            if(isvalid(dist,hour,midspeed)){
                 // cout<<midspeed<<endl;
                ans=midspeed;
                highspeed=midspeed-1;
            }
            else{
                lowspeed=midspeed+1;
            }
        }
        
        return ans;
    }
};