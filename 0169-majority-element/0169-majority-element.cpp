class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt=0,majority=0;
        
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                majority=nums[i];
            }
            
            if(majority==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return majority;
    }
};