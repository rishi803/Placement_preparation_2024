class Solution {
public:
    const int mod=1000000007;
    
    int power(int a,int base){
        
        if(base==0) return 1;
        
        long long ans=power(a,base/2);
        
        if(base%2==0) return ((ans%mod)*(ans%mod))%mod;
        else return a*((ans%mod)*(ans%mod))%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long ans=0;
        
        for(int i=0;i<nums.size();i++){
            
            int ub=upper_bound(nums.begin()+i,nums.end(),target-nums[i])-nums.begin();
            
            ub--;
            
            if(ub>=i)
            ans=(ans+(power(2,ub-i)%mod))%mod;
              // cout<<i<<" "<<ub<<" "<<power(2,ub-i)<<endl;
        }
    
        return ans;
    }
};