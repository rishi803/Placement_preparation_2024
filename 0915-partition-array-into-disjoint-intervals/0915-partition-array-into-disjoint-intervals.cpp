class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int sz=nums.size();
        vector<int>min_on_right(sz);
        min_on_right[sz-1]=nums[sz-1];
        
        for(int i=sz-2;i>=0;i--){
            
            min_on_right[i]=min(min_on_right[i+1],nums[i]);
        }
        
        int cnt=1;
        
        int max_on_left=nums[0];
        
        for(int i=0;i<=sz-2;i++){
            
            max_on_left=max(max_on_left,nums[i]);
            
            if(max_on_left>min_on_right[i+1]) cnt++;
            
            else break;
        }
        
        return cnt;
    }
};