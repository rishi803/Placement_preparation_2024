class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int sz=nums.size();
       sort(nums.begin(),nums.end());
       vector<long long>pre(sz);
        vector<long long>ans;
        pre[0]=nums[0];
        for(int i=1;i<sz;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        
        for(long q:queries){
            
            int idx=upper_bound(nums.begin(),nums.end(),q)-nums.begin();
            if(idx>=nums.size()) ans.push_back (abs(pre[sz-1]-q*(idx)));
           else if(idx==0) ans.push_back(abs(pre[sz-1]-(q*(sz))));
            else{
                long long left=abs(pre[idx-1]-(q*(idx)));
                long long right=abs(pre[sz-1]-pre[idx-1]-(q*(sz-idx)));
               ans.push_back(left+right);
            }
            
        }
        return ans;
    }
};