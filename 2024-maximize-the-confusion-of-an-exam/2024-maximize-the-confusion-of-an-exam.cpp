class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
      
        int head=0,tail=0,cntt=0,cntf=0,mxans=0;
        
        for(head=0;head<s.size();head++){
            if(s[head]=='T') cntt++;
            if(s[head]=='F') cntf++;
            
            while(min(cntt,cntf)>k){
                
                if(s[tail]=='T') cntt--;
                if(s[tail]=='F') cntf--; 
                tail++;
            }
            
            
            mxans=max(mxans,head-tail+1);
        }
        
        return mxans;
    }
};