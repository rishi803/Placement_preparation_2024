class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        vector<int>freq(1e5+1);
        int head=0, tail=0, ans=0;
        
        for(head=0; head<nums.size(); head++){
            freq[nums[head]]++;
            
            ans= max(ans,freq[nums[head]]);
            
            while(tail<= head and (head-tail+1)-ans > k ){
                freq[nums[tail]]--;
                tail++;
            }
        }
        
        return ans;
    }
};