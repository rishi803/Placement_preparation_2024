class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
       
        stack<int>st;
        int mx=INT_MAX;
        
       for(int i=0;i<nums.size();i++){
           if(nums[i]<=mx){
               mx=nums[i];
               st.push(i);
               // cout<<i<<" ";
           }
       }
        
        mx=0;
        
    for(int i=nums.size()-1;i>=0;i--){
        int dist=0;
        while(!st.empty() and nums[i]>=nums[st.top()]){
            
            // cout<<dist<<" ";
            dist= i-st.top();
            st.pop();
        }
        mx=max(mx,dist);
    }
        
        return mx;
    }
};