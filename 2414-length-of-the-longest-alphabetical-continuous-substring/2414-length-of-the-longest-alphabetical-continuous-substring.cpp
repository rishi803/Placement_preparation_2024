class Solution {
public:
    int longestContinuousSubstring(string s) {
        
        int head=0,tail=0,max_ans=1;
        
        for(head=1;head<s.size();head++){
            
            while(head<s.size() and s[head]==s[head-1]+1){
           
                head++;
            }
            
            
             max_ans=max(max_ans,head-tail);
                tail=head;
        }
        
        return max_ans;
    }
};