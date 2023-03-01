class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
     set<int>st;
        for(auto &it:nums){
            int prime=2;
            
            while(it>1){
               
                if(it%prime==0){
                    it/=prime;
                    st.insert(prime);
                }
                else prime++;
                
            }
        }
        return st.size();
    }
};