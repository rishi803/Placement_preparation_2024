class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ans;
        
        stack<char>st;
        unordered_map<char,int>freq;
        unordered_map<char,int>seen;
        
        for(auto i:s){
            freq[i]++;
        }
        
        // for(auto &[key,val]:freq) cout<<key<<" "<<val<<endl;
        
        for(int i=0; i<s.size(); i++){
            
            freq[s[i]]--;
            
            if(seen[s[i]] == 1) continue;
            
            while(!st.empty() and st.top() > s[i] and freq[st.top()] > 0){
                seen[st.top()]= 0;
                st.pop();
                
                // freq[st.top()]--;
            }

            
                 st.push(s[i]);
                 seen[s[i]]= 1;
            
           
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
       
        return  ans;
    }
};