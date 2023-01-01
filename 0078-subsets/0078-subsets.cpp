class Solution {
public:
     vector<vector<int>>ans;
    
    //TEMPLATE
    
    void help(vector<int>&nums,vector<int>&temp,int idx){
        // CONDITION
        ans.push_back(temp);
        
        // FOR LOOP
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);  // operation
            help(nums,temp,i+1); // recursion
            temp.pop_back();          // backtrack;
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        help(nums,temp,0);
        return ans;
    }
};