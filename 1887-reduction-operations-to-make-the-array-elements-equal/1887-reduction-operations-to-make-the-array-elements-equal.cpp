class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        map<int,int, greater<int>>mp;
        
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int cntr= 1;
        int temp= 0;
        int ans= 0;
        int sz= mp.size();
        
        for(auto &[key,val] : mp){
            if(cntr == 1 and sz > 1)
            {
                temp= val;
                ans= val;
            }
            else if(cntr > 1 and cntr < sz)
            {
                mp[key]+=temp;
                temp= mp[key];
                ans+=mp[key];
            }
            
            // cout<<"k "<<key<<" "<<ans<<endl;
    
            cntr++;
        }
        
        return ans;
    }
};