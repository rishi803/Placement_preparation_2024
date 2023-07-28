class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=nums[0],cnt=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==majority) cnt++;
            else{
                if(cnt>0){
                    cnt--;
                }
               if(cnt==0){
                    i++;
                   if(i<nums.size()) majority=nums[i],cnt=1;
                }
            }
        }
        return majority;
    }
};