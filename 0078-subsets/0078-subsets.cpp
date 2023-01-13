class Solution {
public:
    vector<vector<int>>ans;
    
   
    
    void help(vector<int>&nums,vector<int>&temp,int idx){
     
        if(idx==nums.size()) {
              ans.push_back(temp);
            return;
        }
        
        
        
        temp.push_back(nums[idx]);   // pick
        help(nums,temp,idx+1);
        temp.pop_back();         // backtrack
        help(nums,temp,idx+1);     // not pick
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        help(nums,temp,0);
        return ans;
    }
};