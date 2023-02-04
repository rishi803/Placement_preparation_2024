class Solution {
public:
   bool checkInclusion(string s1, string s2) {
      vector<char>v1(128,0);     // you can even optimize it just O(26);
       vector<char>v2(128,0); 
        int s1len=s1.size();
        int s2len=s2.size();
        if(s1len>s2len) return false;
     
        for(int j=0;j<s1len;j++){
            v1[s1[j]]++;
            v2[s2[j]]++;
        }
        if(v1==v2) return true;
        for(int j=s1len;j<s2len;j++){
             
            v2[s2[j]]++;
            v2[s2[j-s1len]]--;
            if(v1==v2) return true;
        }
         if(v1==v2) return true;
        return false;
        
    }
};