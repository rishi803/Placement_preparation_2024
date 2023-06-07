class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ans=0;
      
        for(int i=0;i<32;i++){
            int temp=1<<i;
            int cnt0=0,cnt1=0;
            
            ((temp&a)!=0)?cnt1++:cnt0++;
            ((temp&b)!=0)?cnt1++:cnt0++;
            // cout<<(temp&a)<<" "<<(temp&b)<<" ";
            if((temp&c)!=0){
                // cout<<(temp&c)<<endl;
                if(cnt1==0) ans++;
            }
            else{
                if(cnt1!=0) ans+=cnt1;
            }
            // cout<<"a= "<<ans<<endl;;
        }
        return ans;
    }
};