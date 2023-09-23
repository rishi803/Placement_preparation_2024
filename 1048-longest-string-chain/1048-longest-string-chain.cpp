class Solution {
public:
    
    
    bool check(string word1, string word2){
        
        if(word2.size() + 1 != word1.size()) return false;
        
        int j=0;
        
        for(int i=0; i<word1.size(); i++){
            if(word1[i] == word2[j]){
                j++;
            }
        }
        
        return j==word2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), [&](string &a, string &b){
            return a.size() < b.size();
        });
        
        vector<int>dp(words.size(), 1);
        int ans= 1;
        
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<i; j++){
                
                if(check(words[i], words[j])){
                    dp[i]= max(dp[i], dp[j] + 1);
                }
                
                ans= max(ans, dp[i]);
            }
        }
        
        return ans;
    }
};