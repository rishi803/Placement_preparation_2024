//       [10,2,3,4,5,6,7,8,9,10,99978,99979,99980]

// ans=      0 1 1 1 1 1 1 1  1   2     2    = 12    


//  For the beauty value of the ith element to be 2, it should be greater than all the elements on its left and smaller than all the elements on its right.

// So, it should be greater than the maximum of all elements on the left and smaller than minimum of all elements on the right.

// For the beauty value of the ith element to be 1, it should firstly not satisfy the above statement and secondly the ith element should be greater than the (i - 1)th element and lesser than (i + 1)th element




class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        
        int sz=nums.size();
        vector<int>min_on_right(sz);
        
        min_on_right[sz-1]=nums[sz-1];
        
        for(int i=sz-2;i>=0;i--){
            min_on_right[i]=min(min_on_right[i+1],nums[i]);
        }
        int ans=0;
        int max_on_left=nums[0];
        
        for(int i=1;i<=sz-2;i++){
            
            if(nums[i]>max_on_left and nums[i]<min_on_right[i+1]) ans+=2;
            
            else if(nums[i]>nums[i-1] and nums[i]<nums[i+1]) ans+=1;
            
            else ans+=0;    // you can skip this but i have write to cover all conditions
            
            max_on_left=max(max_on_left,nums[i]);
        }
        
        return ans;
    }
};