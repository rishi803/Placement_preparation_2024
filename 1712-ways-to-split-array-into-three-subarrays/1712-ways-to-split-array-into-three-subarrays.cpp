class Solution {
public:
    const int mod=int (1e9+7);
    
    int waysToSplit(vector<int>& nums) {
         int i, left, remaining, mid_startpoint, mid_endpoint, max_mid, length, n = nums.size();
        vector<int>sum(n, 0);
        
        long long ans=0;
        
        sum[0] = nums[0];
        for(i = 1; i < n; i++) 
            sum [i] = sum[i-1] + nums[i];
        
        for(i = 0; i < n; i++) {
            
            left = sum[i];
            remaining = sum[n-1] - left;

            max_mid = remaining/2;
            
            // cout<<"i= "<<i<<" sum[i]= "<<sum[i]<<" sum[i]+left= "<<sum[i]+left<<" sum[i]+max_mid= "<<sum[i]+max_mid<<" ";
                 
            mid_startpoint = lower_bound(sum.begin() + i + 1, sum.end(), sum[i] + sum[i]) - sum.begin();
            
            // have to apply search upto n-1 otherwise an empty right part will also be counted
            mid_endpoint = upper_bound(sum.begin() + i + 1, sum.begin() + n - 1  , sum[i] + max_mid) - sum.begin();
            mid_endpoint--;

            length = (mid_endpoint - mid_startpoint + 1);
            
            ans += max(0, length);
            // cout<<ans<<endl;
            
        }
        
        return ans % mod;
    }
};