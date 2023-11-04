class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        priority_queue<int>pq;
        vector<int>ans;
        
        int head=0, tail=0;
        
        for(head= 0; head<k; head++){
            pq.push(nums[head]);
        }
        
        ans.push_back(pq.top());
        
        for(head= k; head<nums.size(); head++){
            
            mp[nums[head-k]]++;
            
            while(pq.size() and mp[pq.top()] > 0){
                  mp[pq.top()] --;
                pq.pop();
              
            }
             pq.push(nums[head]);
         
            ans.push_back(pq.top());
        }
        
        return ans;
    }
};