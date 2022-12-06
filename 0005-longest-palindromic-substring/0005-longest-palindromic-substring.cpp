class Solution {
public:
    string longestPalindrome(string s) {
//         if(s.empty()) return "";
//         if(s.size()==1) return s;
//         string ans;
//         vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        
//         for(int i=0;i<s.size();i++){    // mark diagonal element with single char (i==j) as true;
//             dp[i][i]=true;
//         }
//         int fir=0,sec=0;                      // will store first and last index of palindrom string
//         for(int cnt=1;cnt<s.size();cnt++){
//             int gap=cnt,temp=cnt;                // to traverse diagonal wise we do this 
//             for(int j=0;j<s.size()-temp;j++){
                
//                 if(gap-j==1){                   // word with two char
//                     if(s[j]==s[gap]){
//                         dp[j][gap]=true;       // if both char are equal then palindrome
                        
//                         fir=j;
//                         sec=gap;
//                     }
//                     else dp[j][gap]=false;    // if both char are not equal then not palindrome
//                 }
                
//                else if(s[j]==s[gap]){         // char are more than two then first check first and last char
//                     if(dp[j+1][gap-1]==true){  // also check whether all char except first and last are palindrome by checking diagonally lower char substring
//                         dp[j][gap]=true;
                        
//                             fir=j;
//                             sec=gap;
                        
//                     }
//                     else dp[j][gap]=false;
//                 }
                
//                 else dp[j][gap]=false;
//                 gap++;
                
//             }
//         }
//         for(int k=fir;k<=sec;k++){  // extract the maximum palindrome substring
//             ans+=s[k];
//         }
//         return ans;
//     }
    if(s.size()==1)
            return s;
        int st=0,len=0;   
        for(int i=0;i<s.size();i++){
        //STRING OF ODD LENGTH
            int len1 = expand(s,i,i);
        // STRING OF EVEN LENGTH
            int len2 = expand(s,i,i+1);
           if(max(len1,len2)>len){
               len = max(len1 , len2);
               st= i-(len-1)/2;
           }
        }
        return s.substr(st,len);
    }
    int expand(string s,int i, int j){
        while (j<s.size() && i>=0 && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
};