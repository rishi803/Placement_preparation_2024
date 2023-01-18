class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        
        set<int>st;
        for(int i:nums){
            
            int prime=2;
            while(i>1){
                if(i%prime==0) {st.insert(prime);
                i/=prime;}
                else
                prime++;
                
            }
            
        }
        return st.size();
    }
};