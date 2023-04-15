class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long rightsum=0,cnt=0;
        long long tsum=accumulate(nums.begin(),nums.end()-1,0ll);
        rightsum=nums[nums.size()-1];
    
        for(int i=nums.size()-2;i>=0;i--){
                if(tsum>=rightsum) cnt++;
            tsum-=nums[i];
            
            rightsum+=nums[i];
        
        }
        return cnt;
    }
};