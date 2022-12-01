class Solution {
public:
   bool halvesAreAlike(string s) {
        int n = s.length(), count1 = 0, count2 = 0;
        string s1 = s.substr(0, n/2);
        string s2 = s.substr(n/2);
        for(int i = 0; i<s1.length(); i++){
            char x = tolower(s1[i]);
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') count1++;
        }
        for(int i = 0; i<s2.length(); i++){
            char x = tolower(s2[i]);
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') count2++;
        }
        if(count1 == count2) return true;
        return false;
    }
};