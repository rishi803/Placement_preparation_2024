class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size(),count_0;
        int count_1= count(nums.begin(),nums.end(),1);
 
        int windowsize=count_1;
        count_1=0;
        
         for(int i=0;i<windowsize;i++){  // always maintain window of size (total 1's)
             if(nums[i]==0)count_0++;
        }
        
        int mn=count_0;           //for storing maximum count of 1s in a window
        for(int i=windowsize;i<n+windowsize;i++){
            if(nums[i%n]==0)
                count_0++;
            if(nums[(i-windowsize)]==0)
                count_0--;
            mn=min(mn,count_0);
        }
        
        return mn;
        
    }
};