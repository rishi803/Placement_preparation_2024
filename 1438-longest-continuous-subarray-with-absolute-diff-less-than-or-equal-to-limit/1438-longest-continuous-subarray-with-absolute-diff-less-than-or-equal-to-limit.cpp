class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      
        multiset<int> m;
        int head=0,tail=0,ans=0,mx=INT_MIN,mn=INT_MAX;
        
        for(head=0;head<nums.size();head++){
            m.insert(nums[head]);
            while(!m.empty() && *m.rbegin()-*m.begin()>limit)m.erase(m.find(nums[tail++]));
            // cout<<tail<<head<<" "<<mx<<" "<<mn<<endl;
            ans=max(ans,head-tail+1);
        }
        return ans;
    }
};