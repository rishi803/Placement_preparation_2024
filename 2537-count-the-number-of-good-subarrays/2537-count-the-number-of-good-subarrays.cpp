class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        long long head=0, tail=0, ans= 0;
        long long cnt= 0;
        
        for(head=0; head<nums.size(); head++){
            
            cnt+= mp[nums[head]];
            mp[nums[head]]++;
            
         // if(mp[nums[head]] == 2) cnt+=1;
         // if(mp[nums[head]] > 2) cnt+=mp[nums[head]] - 1;
            
            // cout<<head<<" "<<cnt<<endl;
            
            while(cnt >= k) {
                
                int pair= mp[nums[tail]];
                cnt-= (pair * (pair-1))/ 2;
                
                int nextpair= pair - 1;
                cnt+= (nextpair * (nextpair - 1)) / 2;
                
                if(mp[nums[tail]] != 0)
                mp[nums[tail]]--;
                
                // if(mp[nums[tail]] == 0) mp.erase(nums[tail]);
                
                ans+= nums.size() - head;
                tail++;
            }
        }
        
        return ans;
        
    }
};