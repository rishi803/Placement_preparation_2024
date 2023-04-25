class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
         
        unordered_map<int,int>mp;     // store(modvalue,index)
        int ans=0,sum=0;
        mp[0]=-1;   //  [23,2,4,6,6] and k=7 

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            int mod=sum%k;          // if mod value is repeating it means value between repetition is completely divisible by k;
            
            if(mp.find(mod)!=mp.end()){
                if((i-mp[mod])>1) return true;  // if size of subarray is greater than 1
            }
            
            else           // hmesha nhi dalna sirf else pr dalna ([5,0,0,0] and k=3)
            mp[mod]=i;
        }
        
        return false;
    }
};