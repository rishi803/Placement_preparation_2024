class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int sz= s.size();
        
        unordered_map<string,int>hash;
        
        for(auto i:dictionary) hash[i]=1;
        
        vector<int>dp(sz);
        dp[0]= 1;
        
        for(int current= 0; current<sz; current++){
            
            if(current != 0) dp[current]= dp[current-1] + 1;
            
            for(int start= current; start>=0; start--){
                
                string substr= s.substr(start, current-start+1);
                
                if(hash[substr] > 0){
                    
                    if(start == 0){
                        dp[current]= 0;
                    }
                    else{
                        
                        dp[current]= min(dp[current],dp[start-1]);
                        
                    }
                }
               
                // cout<<start<<" "<<substr<<dp[current]<<endl;
            }
            // cout<<dp[current]<<endl;
        }
        // for(auto i=0; i<dp.size(); i++) cout<<i<<" "<<dp[i]<<endl;
        return dp[sz-1];
    }
};