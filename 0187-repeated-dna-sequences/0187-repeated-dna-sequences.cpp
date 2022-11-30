class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        if(s.size()<10) return {};
        vector<string>ans;
        
        for(int i=0;i<=s.size()-10;i++){
           mp[s.substr(i,10)]++;
        }
        for(auto &it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};