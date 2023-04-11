class Solution {
public:
    
    bool isprime(int num){
        
        if(num==1) return false;
        if(num==2 or num==3 or num==5) return true;
        if(num%2==0) return false;
        if(num%3==0) return false;
        if(num%5==0) return false;
        
        for(int i=5;i<=sqrt(num);i+=6){
            if(num%i==0 or num%(i+2)==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        
        int ansfirst=-1,anssecond=-1,first=-1,second=-1;
        int min_val=INT_MAX;
        
        for(int i=left;i<=right;i++){
            if(isprime(i) and first==-1) first=i;
            
            else if(isprime(i) and second==-1) second=i;
            
            else if(first!=-1 and second!=-1){
                // cout<<i<<" "<<first<<" "<<second<<endl;
                if(second-first < min_val){
                    min_val=second-first;
                    ansfirst=first;
                    anssecond=second;
                }
                if(second-first==1) return {ansfirst,anssecond};
                first=second,second=-1;
            }
            if(first!=-1 and second!=-1 and second-first < min_val) ansfirst=first,anssecond=second;
        }
        
        return {ansfirst,anssecond};
    }
};