class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
       
    if(s.size()<2) return 0;
    int ans=0,j=0;
    bool flag;
    while(true){
        flag=false;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0' and s[i+1]=='1') flag=true,swap(s[i],s[i+1]),i++;
        }
        if(flag) ans++;
        if(!flag) break;
    }
        return ans;
    }
};