class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums),end(nums));
        for(auto i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
           int index=upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
             ans.push_back(index);
        }
       
        return ans;
    }
};