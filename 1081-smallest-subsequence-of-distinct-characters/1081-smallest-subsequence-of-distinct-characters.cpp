// test case :  abba , "cbaacabcaaccaacababa" , "addbbcbdaadbdaadcaabbab" , "accaccbbcc"

class Solution {
public:
    string smallestSubsequence(string s) {
        string ans;
        // set<string>res;
        vector<int>availabel(26);
        vector<bool>include(26);
        unordered_map<char,int>mp;
        for(auto &i:s) availabel[i-'a']++,mp[i]++;
        
        for(int i=0;i<s.size();i++){
            availabel[s[i]-'a']--;
            
            // if(ans.back()=='d' and s[i]=='c') cout<<availabel[3]<<" ";
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
            // if(ans.size()==mp.size()) res.insert(ans);
        }
        return ans;
    }
};