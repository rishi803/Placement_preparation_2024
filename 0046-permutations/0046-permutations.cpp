class Solution {
public:
    vector<vector<int>>ans;
    
    void help(int st,int end,vector<int>nums){
        
        // base condition to stop recursion
        
        if(st==end){
            ans.push_back(nums);
            return;
        }
        
        for(int i=st;i<=end;i++){
            swap(nums[st],nums[i]);
            st++;
            help(st,end,nums);
            st--;  // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int st=0,end=nums.size()-1;
        help(st,end,nums);
        return ans;
    }
};