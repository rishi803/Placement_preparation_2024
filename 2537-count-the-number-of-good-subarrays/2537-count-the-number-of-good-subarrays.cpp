//  [3,3,4,3,2,2,4,3]
//  2

class Solution {
public:
   long long countGood(vector<int>& nums, int k) {
       
        int head = 0, tail = 0 , n = nums.size();
        unordered_map<int,int> mp;
        long long int cnt = 0 , ans = 0;
       
        for(head=0;head<nums.size();head++){
            
            mp[nums[head]]++;
            cnt += mp[nums[head]] - 1;            // calculating subarrays
            
			while(tail < head and cnt >= k){
				ans += n - head;
				mp[nums[tail]]--;
				cnt -= mp[nums[tail]];          // decrementing subarrays
				tail++;
			}
            
        }
        return ans;
    }
};