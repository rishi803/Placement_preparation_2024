class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        long sum=0;
        vector<long>pre(n);
        pre[0]=nums[0];
        vector<long>ans;
        // ans.push_back(pre[0]);
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
            // ans.push_back(pre[i]);
        }
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
               ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        // for(auto i:ans)cout<<i<<" ";
        for(int i=left;i<=right;i++){
           
            sum=(sum+ans[i-1])%(int(1e9+7));
             // cout<<sum<<" ";
        }
        
        return sum;
    }
};