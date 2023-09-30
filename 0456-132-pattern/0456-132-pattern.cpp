class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int third= INT_MIN;
        int largest= nums[size(nums)-1];
        
        stack<int>st;
        st.push(largest);
        
        for(int i=size(nums)-2; i>=0; i--){    
            
            if(nums[i] < third) return true;        // nums[i] < third < second
            
            // cout<<i<<" "<<nums[i]<<" "<<largest<<endl;
            if(!st.empty() and nums[i] > st.top()){             // [7,30,2,4,5,6,7,8,9,10] --> 7,30,8
                largest= nums[i];                              // [1,3,2,4,5,6,7,8,9,10]  ---> 1,3,2
                
                while(!st.empty() and largest > st.top()){
                    third= st.top();
                    st.pop();
                }
            }
            
            st.push(nums[i]);
        }
        
        return false;
        
        
    }
};