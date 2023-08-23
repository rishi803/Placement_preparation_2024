class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int sum=0,lg=0;
        mp[sum]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)  // convert 0 to -1 so question becomes max length subarrays with sum 0
            nums[i]=-1;
        }
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum)!=mp.end()){  // can also use (mp.count(sum));
                lg=max(lg,i-mp[sum]);   // find length where sum is repeated
            }
             else
            {
                mp[sum] = i;   // store the index where we get unique sum
            }
        }
        return lg;
        
    }
};