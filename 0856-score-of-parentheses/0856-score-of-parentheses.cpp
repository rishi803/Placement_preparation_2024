class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int ans=0;
        stack<int>lookup;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='('){ 
                lookup.push(ans);   //  store answer at each opening bracket in stack
                ans=0;                 // reset answer for next opening bracket
            }
            
            else{
                ans=lookup.top()+max(ans*2,1);  // if score is 0 so its () raise 1 else (((....)))
                lookup.pop();
            }
        }
        
        return ans;
        
    }
};