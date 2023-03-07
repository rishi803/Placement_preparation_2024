class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        map<int,pair<int,int>>mp;
        unordered_map<int,int>freq;
        int idx=0;
        for(auto &i:operations){
            mp[idx]={i[0],i[1]};
            idx++;
        }
        idx=0;
        
        for(auto &i:nums){
            freq[i]=idx;
            idx++;
        }
        
        for(auto &[key,val]:mp){
            
            int ind=freq[val.first];
            
            freq.erase(nums[ind]);
            nums[ind]=val.second;
            freq[val.second]=ind;    // after updating value save that value index
            
// ex- after updating 1 to 3 now also save 3 ka index as 1 ka index
            
        }
        
        // for(auto &[key,val]:mp) cout<<key<<" "<<val<<endl;
        
        return nums;
    }
};