class Solution {
public:
    string removeDuplicateLetters(string s) {
             string ans;
        vector<int>availabel(26);
        vector<bool>include(26,false);
    
        for(auto &i:s) availabel[i-'a']++;
        
        for(int i=0;i<s.size();i++){
            
            availabel[s[i]-'a']--;
            
            if(include[s[i]-'a']==true) continue; // if a character is already included no need to include it at current("addbbcbdaadbdaadcaabbab")
            
            while(ans.size() and availabel[ans.back()-'a']>0 and ans.back()>s[i]){
                include[ans.back()-'a']=false;
                ans.pop_back();
            }
            if(include[s[i]-'a']==false){
                include[s[i]-'a']=true;
                ans+=s[i];
            }
           
              // cout<<i<<" "<<ans<<endl;
            // availabel[s[i]-'a']--;     (failing test case: "bcbcbcababa" output should be "bca" but "ab")
            
        }
        return ans;
    }
};