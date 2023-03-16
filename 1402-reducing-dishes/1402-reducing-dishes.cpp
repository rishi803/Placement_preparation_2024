class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        
        sort(sat.begin(),sat.end());
        
        int totalsum=0,ans=0,time=1;
        
        for(int i=0;i<sat.size();i++){
            
            if(sat[i]>=0){
                totalsum+=sat[i];
                ans+=sat[i]*time;
                time++;
            }
        }
        
        int temp=0,prevsum=totalsum;
        
        reverse(sat.begin(),sat.end());
        
        for(int i=0;i<sat.size();i++){
            
            if(sat[i]<0){
                
                temp=sat[i];
                if(ans+prevsum+temp>=ans){
                    ans=ans+prevsum+temp;
                    prevsum+=temp;
                }
            }
        }
        
        return ans;
    }
};