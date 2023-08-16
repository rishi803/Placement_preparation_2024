class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        vector<int>ans;
        
        int head= 0, tail= 0;
        
        for(head= 0; head<k; head++){
            pq.push(nums[head]);
            mp[nums[head]]++;
        }
        
        
        
        ans.push_back(pq.top());
        
        for(head= k; head<nums.size(); head++){
            mp[nums[tail++]]--;
            mp[nums[head]]++;
            pq.push(nums[head]);
            
            while(mp[pq.top()] <=0 ){
                pq.pop();
            }
            
            ans.push_back(pq.top());
        }
        
        return ans;
    }
};