class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            
            while(!st.empty() and st.top()>nums[i] and k-st.size()<=nums.size()-i-1){
                st.pop();
            }
            
            if(st.size()<k) st.push(nums[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};