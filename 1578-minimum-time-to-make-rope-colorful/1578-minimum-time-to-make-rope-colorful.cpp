class Solution {
public:
    int minCost(string colors, vector<int>&cost) {
        
        stack<int>st;
        int mncost=0;
        
        for(int i=0;i<colors.size();i++){
            
            if(!st.empty() and colors[i]==colors[st.top()]){
                
                if(cost[st.top()]<=cost[i]){
                    mncost+=cost[st.top()];
                    st.pop();
                    st.push(i);
                }
                
                else{
                    mncost+=cost[i];
                }
            }
            
            else{
                st.push(i);
            }
        }
        
        return mncost;
    }
};