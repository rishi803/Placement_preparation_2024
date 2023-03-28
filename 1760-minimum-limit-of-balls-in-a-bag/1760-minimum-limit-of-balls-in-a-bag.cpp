class Solution {
public:
    
    bool isvalid(int mid_penalty,vector<int>&nums,int op){
        int cnt=0;
        
        for(auto &i:nums){
             
            cnt+=(i/mid_penalty);
            if(i%mid_penalty==0) cnt--;
        }
        
        return cnt<=op;
        
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        
        int ans=-1;
        
        while(low<=high){
            int mid_penalty=low+(high-low)/2;
            
            if(isvalid(mid_penalty,nums,maxOperations)){
                ans=mid_penalty;
                high=mid_penalty-1;
            }
            else{
                low=mid_penalty+1;
            }
        }
        
        return ans;
    }
};