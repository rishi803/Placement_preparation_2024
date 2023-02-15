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
        
        stack<int>st;
        int ans=0;
        st.push(target[0]);
        ans=target[0];
        for(int i=1;i<target.size();i++){
            
            if( st.top()<target[i]){
                ans+=target[i]-st.top();
            }
            
            st.push(target[i]);
        }
        
        return ans;
    }
};