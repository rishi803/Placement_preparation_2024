class Solution {
public:
    int partitionString(string s) {
       
        unordered_map<char,int>freq;
        int cnt=1;
        for(int i=0;i<s.size();i++){
            if(freq[s[i]]>0){
               freq.clear();
                freq[s[i]]++;
                cnt++;
                
            }
            freq[s[i]]++;
        }
        
        return cnt;
    }
};