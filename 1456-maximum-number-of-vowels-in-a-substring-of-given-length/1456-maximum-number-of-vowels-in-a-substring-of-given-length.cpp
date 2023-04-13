class Solution {
public:
    bool isvowel(char c){
        return c=='a' or c=='e' or c=='o' or c=='i' or c=='u';
    }
    
    int maxVowels(string s, int k) {
        
        int head=0,tail=0,ans=0,cnt=0;
        
        for(head=0;head<k;head++){
            if(isvowel(s[head])) cnt++;
        }
        ans=max(ans,cnt);
        
        for(head=k;head<s.size();head++){
            
            if(isvowel(s[head-k])) cnt--;
            if(isvowel(s[head])) cnt++;
            
            ans=max(ans,cnt);
        }
        
        return ans;
    }
};