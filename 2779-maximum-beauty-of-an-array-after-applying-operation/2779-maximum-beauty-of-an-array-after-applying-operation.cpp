class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-k]++;
            mp[nums[i]+k+1]--;
        }
        int mx=0,overlap=0;
        for(auto [i,j]:mp){
            overlap=overlap+j;
            mx=max(mx,overlap);
        }
        return mx;
    }
};