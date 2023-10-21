class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int time) {
       int sz= nums.size();
        
        vector<int>prefix(sz,1),suffix(sz,1);
        
        for(int i=1; i<sz; i++){
            if(nums[i] <= nums[i-1]) prefix[i]= 1+prefix[i-1];
        }
        
        for(int i=sz-2; i>=0; i--){
            if(nums[i] <= nums[i+1]) suffix[i]= 1+suffix[i+1];
        }
        
        vector<int>ans;
        
        for(int i=1; i<sz-1; i++){
            
            int decreasing= prefix[i-1];
            int increasing= suffix[i+1];
            
            // cout<<i<<" "<<decreasing<<" "<<increasing<<endl;
            
            if(decreasing >= time and increasing >= time) ans.push_back(i);
        }
        
        return ans;
        
    }
};