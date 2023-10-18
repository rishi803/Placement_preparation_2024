class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>ans;
        
        int sz= nums.size();
        vector<int>prefix(sz);
        vector<int>suffix(sz);
        
        prefix[0]= nums[0];
        suffix[sz-1]= nums[sz-1];
        
        for(int i=1; i<sz; i++){
            prefix[i]= prefix[i-1] * nums[i];
        }
        
        for(int i=sz-2; i>=0; i--){
            suffix[i]= suffix[i+1] * nums[i];
        }
        

        
        for(int i=0; i<nums.size(); i++){
            
            if(i==0) ans.push_back(suffix[i+1]);
          else if(i==sz-1) ans.push_back(prefix[i-1]);
            
            else{
                int result= prefix[i-1] * suffix[i+1];
                ans.push_back(result);
                // cout<<i-1<<" "<<i+1<<endl;
            }
        }
        
        return ans;
        
    }
};