class Solution {
public:
    int maximumSwap(int num) {
        vector<int>temp;
        
        while(num > 0){
            temp.push_back(num % 10);
            num/=10;
        }
        reverse(temp.begin(), temp.end());
        
        int sz= temp.size();
        vector<pair<int,int>>suffix(sz);
        
        suffix[sz-1]= {temp[sz-1], sz-1};
        
        for(int i=sz-2; i>=0; i--){
            if(temp[i] > suffix[i+1].first){
                suffix[i]= {temp[i], i};
            }
            
            else suffix[i]= suffix[i+1];
        }
       
      
         for(int i= 0; i< sz; i++){
            if(temp[i] < suffix[i].first){
                swap(temp[i], temp[suffix[i].second]);
                break;
            }
          
         }
        int ans= 0;
        
          for(auto i:temp) {
              // cout<<i;
              ans= ans*10+i;
          }
        return ans;
    }
};