class Solution {
public:
    
    int help(int number, int resultant){
        
        int requirednum= 0;
        
        
        for(int i=31; i>=0; i--){
            int numberbit= number & (1<<i);
            int resultantbit= resultant & (1<<i);
            
            if(numberbit > 0) numberbit = 1;
            if(resultantbit > 0) resultantbit= 1;
            
            
            if(resultantbit == 0){
                requirednum= requirednum * 2 + numberbit;
            }
            else{
                 requirednum= requirednum * 2 + !numberbit;
            }
        }
        
        return requirednum;
    }
    vector<int> findArray(vector<int>& pref) {
        
        vector<int>ans;
     
        
        ans.push_back(pref[0]);
        
        for(int i=1; i<pref.size(); i++)
        {
            int result= help(pref[i-1], pref[i]);
            
            ans.push_back(result);
        }
        
        return ans;
    }
};