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
            
    
            nums[ind]=val.second;
            freq[val.second]=ind;
            
        }
        
        // for(auto &[key,val]:mp) cout<<key<<" "<<val<<endl;
        
        return nums;
    }
};