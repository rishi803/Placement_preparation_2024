class Solution {
public:
    
    bool isvalid(int canans,vector<int>&nums,int p){
        
        int cnt=0;
        
        for(int i=1;i<nums.size();i++){
            
           if(nums[i]-nums[i-1]<=canans) {
               // if(canans==0) cout<<nums[i]<<" b "<<nums[i-1]<<endl;
               cnt++;
               i++;
           }
        
            
        }
        // cout<<cnt<<endl;
        
        return cnt>=p;
        
    }
    int minimizeMax(vector<int>& nums, int p) {

        int ans=0;
     
        sort(nums.begin(),nums.end());
        
        int l=0,h=nums[nums.size()-1] - nums [0];
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(isvalid(mid,nums,p)){
                // cout<<" m= "<<mid<<endl;
                ans=mid;
                h=mid-1;
            }
            
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};