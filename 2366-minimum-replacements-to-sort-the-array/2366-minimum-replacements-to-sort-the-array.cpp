class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int sz= nums.size();
        int prev= nums[sz-1];
        long long operation= 0;
        
        for(int i=sz-2; i>=0; i--){
            if(nums[i] > prev ){
             int temp = nums[i] / prev;  // Calculate how many times the element needs to be divided
                if (nums[i] % prev) temp++; // If there's a remainder, increment 'temp'
                prev = nums[i] / temp;  // Update 'prev' for the next comparison
                operation += temp - 1; // Add (temp - 1) to 'operation' for the number of operations
            }
            else{
                prev= nums[i];
            }
        }
        
        return operation;
    }
};