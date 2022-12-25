class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums),end(nums));
        for(auto i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
               if(queries[i]>=nums[nums.size()-1]) {ans.push_back(nums.size());
                                                     continue;}
            for(int j=0;j<nums.size();j++){
                if(nums[j]>queries[i]){
                    ans.push_back(j);
                    break;
                }
              
            }
             
        }
       
        return ans;
    }
};