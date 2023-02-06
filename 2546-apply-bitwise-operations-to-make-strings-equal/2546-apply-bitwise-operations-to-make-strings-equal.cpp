class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        if(s==target) return true;
        
        if(count(s.begin(),s.end(),'1') and count(target.begin(),target.end(),'1')) return true;
        else return false;
        
    }
};