class Solution {
public:
     vector<vector<int>>v;
    void help(int s,int e,vector<int>nums){
        if(s==e){
            v.emplace_back(nums);
            return ;
        }
        for(int i=s;i<=e;i++){
            if(nums[i]==nums[s] and i!=s) continue;
            swap(nums[s],nums[i]);
            s++;
            help(s,e,nums);
            s--;
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0,e=nums.size()-1;
        help(s,e,nums);
        return v;
    }
};