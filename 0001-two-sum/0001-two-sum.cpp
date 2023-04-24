class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     if(mp.find(target-nums[i])!=mp.end()) return{mp[target-nums[i]],i};
        //     mp[nums[i]]=i;
        // }
        // return {};
        
        vector<int> output;
        for (int i = 0; i < nums.size(); i++){
            for (int j = 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target && i != j){
                    output.push_back(i);
                    output.push_back(j);
                    return output;
                }
            }
        }
        return output; 
    }
};