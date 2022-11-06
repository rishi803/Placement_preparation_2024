class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto &it:arr){
            mp[it]++;
        }
        int cnt=0,ans=0;
        sort(arr.begin(),arr.end(),[&](int a,int b){
            return mp[a]>mp[b];
        });
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
       for(int i=0;i<arr.size();i++){
           if(mp.find(arr[i])!=mp.end()){
               cout<<arr[i]<<endl;
              ans++;
               cnt+=mp[arr[i]];
               mp.erase(arr[i]);
           } 
           if(cnt>=n/2) return ans;
       }
        return 0;
    }
};