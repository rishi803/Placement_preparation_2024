class Solution {
public:
    int maximumSwap(int num) {
        vector<int >v;
            
        while(num)
        {
            int r = num%10;
           v.push_back(r);
            num/=10;
        }
        
        reverse(v.begin(),v.end());
        
        
        int n= v.size();
        
        vector<pair<int,int>>smax(n);
        smax[n-1].first = v[n-1];
        smax[n-1].second = n-1;
        
       
        
        for(int i = n-2; i>=0; i--)
        {
            if(v[i] <= smax[i+1].first){
                smax[i]=smax[i+1];
            }
            else
                smax[i]={v[i],i};
        }
        
        // for(auto i:smax){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        
        for(int i =0;i<n;i++)
        {
            if(smax[i].first > v[i])
            {
                int swapidx= smax[i].second;
                
                swap(v[swapidx], v[i]);
                break;
            }
        }
        int numi= 0;
        
        for(int i=0; i<v.size(); i++){
            numi= numi * 10 + v[i];
        }
        
        
        return numi;
        
    }
};