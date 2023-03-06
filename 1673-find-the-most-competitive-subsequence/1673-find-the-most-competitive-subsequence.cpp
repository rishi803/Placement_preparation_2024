// think about this test case [3,5,2,6]  and k=4   ANSWER=[3,5,2,6]  for k=2  ANSWER=[2,6]


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        vector<int>ans;
        
        for(auto i=0;i<nums.size();i++){
            
            while(st.size() and k and st.top()>nums[i] and nums.size()-i>k-st.size() ){
                st.pop();
            }
            if(st.size()<k)
            st.push(nums[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};