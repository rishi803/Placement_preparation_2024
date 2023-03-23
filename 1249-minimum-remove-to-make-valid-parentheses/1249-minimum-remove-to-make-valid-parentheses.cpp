class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        vector<bool>not_included(s.size());
        string ans;
        stack<pair<char,int>>st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({'(',i});
            }
            else if(s[i]==')'){
                if(!st.empty()) st.pop();
                else not_included[i]=1;
            }
        }
        while(!st.empty()) {
             int idx=st.top().second;
            not_included[idx]=1;
            st.pop();
                }
        
        for(int i=0;i<s.size();i++){
            if(not_included[i]==0) ans+=s[i];
        }
        return ans;
    }
};