class Solution {
public:
    vector<vector<int>>ans;
    
    void help(vector<int>&nums,int idx,vector<int>&temp){
        
        if(temp.size()>=2){
            ans.push_back(temp);
        }
         unordered_set<int>st;
        for(int i=idx;i<nums.size();i++){
           
            if(st.find(nums[i])==st.end() and ( temp.empty() or nums[i]>=temp.back())){
            temp.push_back(nums[i]);
            help(nums,i+1,temp);
            temp.pop_back();
            st.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        help(nums,0,temp);
        return ans;
    }
};