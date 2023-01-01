class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        
        set<int>st;
        int n=nums.size();
        
    for(int i=0;i<nums.size();i++){
        
        int prime=2;
        
        while(nums[i]>1){
            
            if(nums[i]%prime==0){
                st.insert(prime);
                nums[i]/=prime;
            }
            else{
                prime++;
            }
        }
       
        
    }
        
         return st.size();
        
    }
};