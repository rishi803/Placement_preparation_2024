class Solution {
public:
    
    bool isvalid(int mid_day,vector<int>&bloomDay,int m,int k){
        
        int size=0,cnt=0;
        
        for(int i=0;i<bloomDay.size();i++){
            
            if(bloomDay[i]>mid_day){
                size=0;
            }
            else size++;
            
            if(size==k){
                cnt++;
                size=0;
            }
            
        }
        
        return cnt>=m;
  }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(m*k>bloomDay.size()) return -1;
        
     
        
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        
        int ans=-1;
        
        while(low<=high){
            
            int mid_day=low+(high-low)/2;
            
            if(isvalid(mid_day,bloomDay,m,k)){
                ans=mid_day;
                high=mid_day-1;
            }
            else{
                low=mid_day+1;
            }
        }
        
        return ans;
    }
};