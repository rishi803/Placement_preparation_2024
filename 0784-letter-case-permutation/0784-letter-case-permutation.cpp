class Solution {
public:
    vector<string>ans;
    
     void help(string &s , int idx){
        
          ans.push_back(s);
         
        if(idx>=s.size()){
           
            return;
        }
        for(int i=idx;i<s.size();i++){
            
            if(isalpha(s[i])){
               
             s[i]^=(1<<5);
            
            help(s,i+1);
                
             s[i]^=(1<<5);
            
            }
           
            
        }
    }
    vector<string> letterCasePermutation(string s) {
       
         help(s,0);
        return ans;
    }
};