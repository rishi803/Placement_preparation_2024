class Solution {
public:
    char findTheDifference(string s, string t) {
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int i=0;
        
        while( i < (min(s.size(),t.size())) ){
            if(s[i] != t[i]) return t[i];
            i++;
        }
        
        return t[t.size()-1];
    }
};