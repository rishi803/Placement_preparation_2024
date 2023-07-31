class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<int>pq;
        int head=0;
        
        for(head=0;head<k-1;head++){
            pq.push(nums[head]);
            
        }
     
        
        for(head=k-1;head<nums.size();head++){
            
            pq.push(nums[head]);
            
            while(mp[pq.top()]>0){
                
                int temp=pq.top();
                pq.pop();
                mp[temp]--;
                
            }
             
            ans.push_back(pq.top());
             mp[nums[head-k+1]]++;
        }
        return ans;
        
    }
};