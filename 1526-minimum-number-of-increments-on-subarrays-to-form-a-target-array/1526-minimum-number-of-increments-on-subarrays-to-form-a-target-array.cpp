// agr elements decrease ho rhe to pichla max ans hi ans rhega kunki utna operation laga hi hoga lkin jaise element increase hona chalu ho to pichla ans + current difference jo aya

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
//         vector<int>dp(target.size());
//         dp[0]=target[0];
        
//         for(int i=1;i<target.size();i++){
//             if(target[i]<=target[i-1]) dp[i]=dp[i-1];
//             else{
//                  dp[i]=dp[i-1]+(target[i]-target[i-1]);
//             }
//         }
//         return dp[dp.size()-1];
        
        int ans=target[0];
        
        for(int i=1;i<target.size();i++){
             if(target[i]>target[i-1]) 
            
                 ans+=(target[i]-target[i-1]);
            }
        return ans;
        
        
//         stack<int>st;
//         int ans=0;
//         st.push(target[0]);
//         ans=target[0];
//         for(int i=1;i<target.size();i++){
            
//             if( st.top()<target[i]){
//                 ans+=target[i]-st.top();
//             }
            
//             st.push(target[i]);
//         }
        
//         return ans;
    }
};