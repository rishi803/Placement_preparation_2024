class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int head=0,tail=0;
        long long sum= 0;
        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq; // small on top  (try to store lowest sum on top ---> monotonic increasing sum to apply sliding window)
        
        int ans= nums.size()+1;
        
        for(head=0; head<nums.size(); head++){
            sum+=nums[head];
            
            if(sum >= k)
           {
                ans= min(ans, head-tail+1);
           }
            
            while(pq.size() and sum - (pq.top().first) >= k){
                // cout<<sum<<" "<<pq.top().first<<endl;
                ans= min(ans, head-pq.top().second); // check current sum - (lowest prev sum) [4,-3,3,3,5] target = 5
                pq.pop();
            }
            
           pq.push({sum,head});
        }
        
        return ans==nums.size()+1 ? -1 : ans;
    }
};