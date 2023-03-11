class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        long long ans=0;
        
        int temp=nums[0];
        string stemp=to_string(temp);
        reverse(stemp.begin(),stemp.end());
        int extract=stoi(stemp);
        
        mp[nums[0]-extract]=1;
        
        for(int i=1;i<nums.size();i++){
            
            
        int temp=nums[i];
        string stemp=to_string(temp);
        reverse(stemp.begin(),stemp.end());
        int extract=stoi(stemp);
        
            if(mp.find(nums[i]-extract)!=mp.end()) ans+=mp[nums[i]-extract];
            
            mp[nums[i]-extract]++;
            
        }
        
        return ans%(int(1e9+7));
    }
};