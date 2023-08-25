class Solution {
public:
    string decodeString(string s) {
        
        stack<char>st;
        string ans;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i] == ']'){
                string temp;
                string num;
                while(!st.empty() and st.top() != '['){
                    temp+= st.top();
                    st.pop();
                }
                st.pop();             // to pop "["   
           
                while(!st.empty() and st.top() >= '0' and st.top() <= '9'){
                   num+= st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                reverse(temp.begin(), temp.end());
                int times= stoi(num);
                
                while(times--){
                    for(int i=0; i<temp.size(); i++){
                        st.push(temp[i]);
                    }
                }
               
            }
            else{
               
                st.push(s[i]);
            }
            
        }
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};