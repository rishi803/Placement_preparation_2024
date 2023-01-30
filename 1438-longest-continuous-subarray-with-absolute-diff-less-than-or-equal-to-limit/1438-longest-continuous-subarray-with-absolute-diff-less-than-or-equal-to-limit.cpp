class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      
        deque<int> maxd, mind;
        int head=0,tail=0,ans=0,mx=INT_MIN,mn=INT_MAX;
        
        for(head=0;head<nums.size();head++){
            while (!maxd.empty() && nums[head] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && nums[head] < mind.back()) mind.pop_back();
            maxd.push_back(nums[head]);
            mind.push_back(nums[head]);
           while (maxd.front() - mind.front() > limit) {
                if (maxd.front() == nums[tail]) maxd.pop_front();
                if (mind.front() == nums[tail]) mind.pop_front();
                ++tail;
            }
              ans=max(ans,head-tail+1);
        }
        return ans;
    }
};