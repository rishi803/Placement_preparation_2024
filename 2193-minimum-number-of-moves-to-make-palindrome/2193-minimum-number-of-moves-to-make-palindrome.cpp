class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int i=0,j=s.size()-1;
        
        int cnt=0;
        
       while(i<j){
           
          if(s[i]==s[j]){
              i++;
              j--;
          }
           else{
               
               int found=-1;
               
               for(int k=j-1;k>i;k--){            // search nearer to j so that need minimum swaps
                   if(s[k]==s[i]){
                       found=k;
                       break;
                   }
               }
               
               if(found!=-1) {
                   for(int i=found;i<j;i++){
                       swap(s[i],s[i+1]);
                       cnt++;
                   }
                   i++;
                   j--;
               }
               
               else{
                   swap(s[i],s[i+1]);
                   cnt++;
                   // cout<<s<<endl;
                  
               }
           }
       }
        
        return cnt;
    }
};