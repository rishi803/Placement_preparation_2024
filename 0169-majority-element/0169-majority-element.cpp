class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt=1,majority=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(cnt==0) {
            cnt++;
            majority= nums[i];
            }
            else if(nums[i]!=majority){
                if(cnt<=1)
                majority=nums[i];
                cnt--;
            }
            if(nums[i]==majority) cnt++;
        }
        return majority;
    }
};