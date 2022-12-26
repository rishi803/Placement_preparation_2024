class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(auto it:num){
            while(k and ans.size() and it<ans.back()){
                ans.pop_back();
                k--;
            }
           if(ans.size() or it!='0') ans+=it;
        }
         while(k-- and ans.size()) ans.pop_back();
        return ans.size()==0?"0":ans;
    }
};