class Solution {
public:
    
int ans = INT_MAX;
    void solve(int start, vector<int>& nums, vector<int>& v, int k){
        if(start==nums.size()){
            int maxm = INT_MIN;
            for(int i=0;i<k;i++){
                // cout<<v[i]<<" ";
                maxm = max(maxm,v[i]);
            }
            // cout<<endl;
            // cout<<" max= "<<maxm<<endl;
            ans = min(ans,maxm);
            return;
        }
        // cout<<endl;
        for(int i=0;i<k;i++){
            v[i] += nums[start];
            solve(start+1,nums,v,k);
            v[i] -= nums[start];
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
         // v[0]+=nums[0] ;   // n>=2     
        solve(0,nums,v,k);
        return ans;
    }
};