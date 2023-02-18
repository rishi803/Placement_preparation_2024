class Solution {
public:
    
    bool isValid(int product,vector<int>&quan,int n){
        
        int cnt=0;
        for(int i=0;i<quan.size();i++){
            cnt+=quan[i]/product;
            if(quan[i]%product!=0) cnt++;
        }
        
        return cnt<=n;
        
    }
    int minimizedMaximum(int n, vector<int>& quan) {
        int ans=0;
        int low=1;
        int high=*max_element(quan.begin(),quan.end());
        
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(isValid(mid,quan,n)){
                ans=mid;
                high=mid-1;;
            }
            
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};