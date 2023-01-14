class Solution {
public:
    vector<string>ans;
    
     void help(string &s , int idx){
        if(idx==s.size()){
            ans.push_back(s);
            return;
        }
         help(s,idx+1);                // not take
         if(isalpha(s[idx])){           // take
             s[idx]^=32;
             help(s,idx+1);
         }
         
         
         
         
    }
    vector<string> letterCasePermutation(string s) {
       
         help(s,0);
        return ans;
    }
};