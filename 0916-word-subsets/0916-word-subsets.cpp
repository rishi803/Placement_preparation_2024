class Solution {
public:
    
      vector<int> giveFreq(string s)
    {
        vector<int> freq(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
    
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
         vector<int> max_Freq_w2(26, 0);
        
        bool flag=true;
     int cnt=-1;
        map<char,int>hash;
        
        for(int i=0;i<words2.size();i++){
            
            vector<int>freq=giveFreq(words2[i]);
             for(int i = 0; i < 26; i++)
            {
                max_Freq_w2[i] = max(freq[i], max_Freq_w2[i]);  // upadate freq to max freq
            }
        }
        // for(auto [x,y]:hash) cout<<x<<y<<endl;
        
        for(auto &x : words1)
        {
            vector<int> freq = giveFreq(x);  // gives freq of characters for word in words1
            bool flag = true;
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] < max_Freq_w2[i]) // specifies that word did not have all the characters from word2 array
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(x);   // string x is Universal string
        }
        return ans;
    }
};