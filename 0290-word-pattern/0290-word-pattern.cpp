class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        stringstream ss(s);
        vector<string>word;
        string st;
        
        while(ss>>st){
            word.push_back(st);
        }
        
        if(pattern.size()!=word.size()) return false;
        unordered_map<char,string>mp;
        set<string>ste;
        
        
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]]!=word[i]) return false;
            }
            else{
                mp[pattern[i]]=word[i];
                ste.insert(word[i]);
            }
        }
        return ste.size()==mp.size();
    }
};