class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int mx= *max_element(nums.begin(), nums.end());
        
        int cnt= 0;
        long long head=0, ans= 0;
        int tail= 0;
        
        for(head= 0; head<nums.size(); head++){
            if(nums[head] == mx) cnt++;
            
            while(cnt >= k){
                ans+= (nums.size() - head);
                if(nums[tail] == mx) cnt--;
                tail++;
            }
        }
        
        return ans;
    }
};