class Solution {
public:
    bool detectCapitalUse(string s) {
        int idx=-1,cnt=0;
        for(int i=0;i<s.size();i++){
            
            if(s[i]>='A' and s[i]<='Z') cnt++,idx=i;
        }
        if(cnt==s.size()) return true;
        else if(cnt==1 and idx==0) return true;
        else if(cnt==0) return true;
            return false;;
    }
};