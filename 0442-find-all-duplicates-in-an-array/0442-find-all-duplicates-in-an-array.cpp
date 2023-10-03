// cycle sort

class Solution {
public:
       vector<int> findDuplicates(vector<int>& nums) {
       
        int i = 0,k=0;
        for(i=0;i<nums.size();i++){ //cyclic sort
            
            while(nums[i] != i+1 and nums[i] != nums[nums[i]-1]){
               swap(nums[i],nums[nums[i]-1]);
             }
           //   for(int i=0; i<nums.size(); i++){
           //     cout<<i<<" "<<nums[i]<<endl;
           // }
            
            // cout<<endl;
           
        }
           
           // for(int i=0; i<nums.size(); i++){
           //     cout<<i<<" "<<nums[i]<<endl;
           // }
           
		//search for duplicate numbers
        for(i = 0; i<nums.size(); i++){
            if(nums[i] != i+1){
                nums[k++]=nums[i];
            }
        }
           nums.resize(k);
        return nums;
    }
};
