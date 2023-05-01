class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t=0,f=0,head=0,tail=0,ans=0;
        
        for(head=0;head<answerKey.size();head++){
            if(answerKey[head]=='T') t++;
            if(answerKey[head]=='F') f++;
            
            while(min(t,f)>k){
                if(answerKey[tail]=='T') t--;
                if(answerKey[tail]=='F') f--;
                
                tail++;
            }
            
            ans=max(ans,head-tail+1);
        }
        
        return ans;
    }
};