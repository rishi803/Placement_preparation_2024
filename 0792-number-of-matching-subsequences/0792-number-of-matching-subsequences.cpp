class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>>freq(26);
        
        for(auto i=0;i<s.size();i++){
            freq[s[i]-'a'].push_back(i);
        }
        
        // for(auto i:freq){
        //     for (auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int ans=words.size();
        
        for(auto &word:words){
            int last=-1;
            for(int j=0;j<word.size();j++){
                
               auto idx=upper_bound(freq[word[j]-'a'].begin(),freq[word[j]-'a'].end(),last);
                
                if(idx==freq[word[j]-'a'].end()) {
                    
                    ans--;
                    break;
                }
                else {
                    last=*idx;
                }
            }
            
            
        }
        return ans;
        
    }
};