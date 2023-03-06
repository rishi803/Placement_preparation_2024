// test case :  abba , "cbaacabcaaccaacababa" , "addbbcbdaadbdaadcaabbab" , "accaccbbcc" , "bcbcbcababa"

class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        vector<int>availabel(26);
        vector<bool>include(26);
    
        for(auto &i:s) availabel[i-'a']++;
        
        for(int i=0;i<s.size();i++){
            
            availabel[s[i]-'a']--;
            
            if(include[s[i]-'a']==true) continue;
            
            while(ans.size() and availabel[ans.back()-'a']>0 and ans.back()>s[i]){
                include[ans.back()-'a']=false;
                ans.pop_back();
            }
            if(include[s[i]-'a']==false){
                include[s[i]-'a']=true;
                ans+=s[i];
            }
           
              // cout<<i<<" "<<ans<<endl;
            // availabel[s[i]-'a']--;            (failing test case: "bcbcbcababa")
            
        }
        return ans;
    }
};