class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;
        stack<int>st;
        
        for(int &i:ast){
            
            if(i>0){
                st.push(i);
                
            }
            
            else{
                
                while(!st.empty() and st.top()>0 and st.top()<abs(i)) st.pop();  // +ve aur -ve ka collision only that's whhy st.top()>0 becaue stack can also contain -ve element (-2,-1,1,2 test case)
                
                
                
                if(!st.empty() and st.top()>abs(i)) continue;
                
                if(!st.empty() and st.top()==abs(i)) st.pop();
                
                else if(st.empty() or st.top()<0) st.push(i); // agar phle se negative h aur dubara -ve ata h to bhi dal do stack me
                
                
            }
        }
        while(!st.empty()) ans.push_back(st.top()),st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};