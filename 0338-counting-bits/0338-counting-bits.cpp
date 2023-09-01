class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans;
        
        for(int i=0; i<=n; i++){
            
            int cnt1= 0;
            int temp= i;
            
            while(temp > 0){
                int dig= temp & 1;
                if(dig == 1) cnt1++;
                
                temp>>=1;
            }
           // cout<<i<<endl;
            ans.push_back(cnt1);
        }
        
        return ans;
    }
};