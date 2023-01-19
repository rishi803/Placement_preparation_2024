class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0,cnt=0,rem=0;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
           rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.find(rem)!=mp.end()) cnt+=mp[rem];
            mp[rem]++;
        }
        return cnt;
    }
};