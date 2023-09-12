class Solution {
public:
    int minDeletions(string s) {
        
        int arr[26]= {0};
        
        for(auto i:s){
            arr[i-'a']++;
        }
        
        map<int,int,greater<int>>mp;
        
        for(int i=0; i<26; i++){
            if(arr[i] != 0)
            mp[arr[i]]++;
        }
        // for(auto [x,y]:mp) cout<<x<<" "<<y<<endl;
        
        int deletion= 0;
        
        for(auto [x,y] : mp){
            // cout<<x<<" "<<y<<endl;
            
            while(mp[x] > 1){
                mp[x]--;
                if(x-1 != 0){
                     mp[x-1]++;
                }
               
                deletion++;
            }
        }
        return deletion;
    }
};