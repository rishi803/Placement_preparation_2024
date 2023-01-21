class Solution {
public:
    void help(vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates,int sum, int target,int idx){
        if(sum>target) return ;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
            
        for(int i=idx;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            help(ans,temp,candidates,sum+candidates[i],target,i);
            temp.pop_back();
        }    
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        // sort(candidates.begin(),candidates.end());
        help(ans,temp,candidates,0,target,0);
        return ans;
    }
};