class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        int head=0,tail=0,ans=0;
        char cur='a',next='e';
        for(head=0;head<word.size();head++){
            
                 tail=head;
            
            if(word[head]=='a'){
               while((head<word.size() and word[head]==cur) or (head<word.size() and next!='a' and word[head]==next)){
                   
                cur=word[head];
                if(cur=='a') next='e';
                if(cur=='e') next='i';
                if(cur=='i') next='o';
                if(cur=='o') next='u';
                if(cur=='u') next='a';   
                 head++;
                
            }
                head--;
                if(next=='a') 
                ans=max(ans,head-tail+1);
            
            }
            cur='a',next='e';
         
         
        }
      
        return ans;
    }
};