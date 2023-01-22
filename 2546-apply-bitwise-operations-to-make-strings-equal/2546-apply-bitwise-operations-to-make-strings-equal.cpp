class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        sort(s.begin(),s.end());
        sort(target.begin(),target.end());
        int num_target=0;
        for(auto &i:target) num_target+=(i-'0');
        
        if(s==target) return true;
        else if(num_target!=0){
            if(find(s.begin(),s.end(),'1')!=s.end()) return true;
        }
        return false;
    }
};