class Solution {
public:
    
    vector<int>v;
    int ans=INT_MAX;
    
    void help(vector<int>&cookies,int k,int idx){
    
        
        if(idx==cookies.size()) {
            // cout<<v[0]<<" "<<v[1]<<endl;
            int mxans=0;
            for(int i=0;i<v.size();i++){
                mxans=max(mxans,v[i]);
               
            }
            // cout<<mxans<<endl;
            ans=min(mxans,ans);
            return;
        }
        for(int i=0;i<k;i++){
            v[i]+=cookies[idx];
            help(cookies,k,idx+1);
            v[i]-=cookies[idx];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        
      v.resize(k);
      help(cookies,k,0);
        return ans;
    }
};