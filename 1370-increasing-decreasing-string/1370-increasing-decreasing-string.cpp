class Solution {
public:
    
    void remove(string &s, char ch) {
    int index = s.find(ch); 

    if (index != string::npos) {  
        s.erase(index, 1);
    }
}

    string sortString(string s) {
       
     
        string ans;
        map<char,int>mp;
      
        for(auto i:s) mp[i]++;
      
        while(s.size()){
              set<char>st;
               set<char,greater<char>>st1;
            for(auto i:s){
            if(mp[i]>0){
              st.insert(i);  
            }
            
          
        }
        for(auto i:st) {
            ans+=i;
            mp[i]--;
            remove(s,i);
        }
        
         
        for(auto i:s){
            if(mp[i]>0){
                st1.insert(i);
            }
        }
        // cout<<" ";
        for(auto i:st1) {
            ans+=i;
            mp[i]--;
            remove(s,i);
        }
         
            // cout<<s<<" "<<ans<<endl;
        }
        
        return ans;
    }
};