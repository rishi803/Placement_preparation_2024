class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int head= 0,tail=0,ans=0;                  // declare global variables
        int count[3] = {0, 0, 0};                 // extra array to count frequency
        
        for (head = 0; head < s.size(); head++) {
             count[s[head] - 'a']++;              // do operation (store frequency)
            
             while (count[0]>0 && count[1]>0 && count[2]>0){
                 count[s[tail]-'a']--;           // remove elements from tail to get out of while loop
                 tail++;
             }
                
            ans+=tail;       // store the answer
        }
        return ans;         // return the answer
    }
};