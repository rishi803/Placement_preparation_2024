// Logic--> binary searh on answer


bool isvalid(long long mid_can_mx,vector<int>&nums){
  
    long long temp=0;
    
    for(int i=0;i<nums.size();i++){
        
        if(nums[i]<=mid_can_mx){
            temp+=mid_can_mx-nums[i];
        }
        else{
            if(nums[i]-mid_can_mx > temp) return false;
            temp-=(nums[i]-mid_can_mx);
        }
    }
    return true;
  
}

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int sz=nums.size();
        long long l=0;
        long long h=*max_element(begin(nums),end(nums));

        int ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            
            // cout<<mid<<endl;
            if(isvalid(mid,nums)){
                // cout<<mid<<endl;
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