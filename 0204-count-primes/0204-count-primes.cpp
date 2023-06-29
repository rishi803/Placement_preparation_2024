class Solution {
public:
    
    vector<bool>v;
    int cnt=0;
    
    void seive(int n){
        
        for(int i=2;i*i<=n;i++){
            if(v[i]!=1)
            for(int j=i+i;j<=n;j+=i){
                v[j]=1;
            }
        }
    }
    
    int countPrimes(int n) {
        // if(n==0) return 0;
        v.resize(n+1,0);
        // v[0]=1,v[1]=1;
        seive(n);
        
        for(int i=2;i<n;i++){
           if(v[i]==0) cnt++;
        }
        return cnt;
    }
};