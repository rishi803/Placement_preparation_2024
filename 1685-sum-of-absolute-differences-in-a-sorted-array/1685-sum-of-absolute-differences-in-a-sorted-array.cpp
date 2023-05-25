// exactly same as https://leetcode.com/problems/intervals-between-identical-elements/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sz=nums.size();
        vector<int>prefix=nums;
        vector<int>result(sz);
        
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
            // cout<<prefix[i]<<" ";
        }
        
        result[0]=abs((sz-1)*nums[0]-(prefix[sz-1]-prefix[0]));
        
        for(int i=1;i<nums.size();i++){
            int left=abs((i*nums[i])-prefix[i-1]);
            int right=abs((sz-i-1)*nums[i]-(prefix[sz-1]-prefix[i]));
            
            result[i]=left+right;
        }
        
        return result;
    }
};