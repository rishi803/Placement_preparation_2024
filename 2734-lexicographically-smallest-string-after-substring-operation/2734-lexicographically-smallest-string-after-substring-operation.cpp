class Solution {
public:
//     s = "leetcode"
// Output: "kddsbncd"
 
//     s = "acbbc"
// Output: "abaab"
    
//     s = "cbabc"
// Output: "baabc"
    
    string smallestString(string s) {
        
        int start=0;
        while(s[start]=='a')start++;    // skip if 'a' is occuring as substring from starting
        if(start==s.size()){                 // if reaches to last so we have to do exactly 1 operation so just change last one
            s[s.size()-1]='z';              
        }
        for(int i=start; i<s.size(); i++){
            if(s[i]=='a')return s;      
            else{
                s[i]=s[i]-1;   // else not 'a' means we can easily go prev to get smaller character
            }
        }
        return s;
    }
};